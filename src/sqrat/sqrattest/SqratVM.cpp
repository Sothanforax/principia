//
// Copyright (c) 2012 Li-Cheng (Andy) Tai, atai@atai.org
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
//  1. The origin of this software must not be misrepresented; you must not
//  claim that you wrote the original software. If you use this software
//  in a product, an acknowledgment in the product documentation would be
//  appreciated but is not required.
//
//  2. Altered source versions must be plainly marked as such, and must not be
//  misrepresented as being the original software.
//
//  3. This notice may not be removed or altered from any source
//  distribution.
//


#include <gtest/gtest.h>
#include <sqrat.h>
#include <sqrat/sqratVM.h>
#include "Fixture.h"
/* test demonstrating Sourceforge bug 3507590 */
   
using namespace Sqrat;

class simpleclass 
{
public:
    simpleclass() {}
    void memfun() {}
};

void bind(HSQUIRRELVM vm)
{
    Sqrat::Class<simpleclass> sqClass(vm);
    sqClass               
    .Func(_SC("memfun"), &simpleclass::memfun);
    Sqrat::RootTable(vm).Bind(_SC("simpleclass"), sqClass);    

}

TEST_F(SqratTest, SqratVM)
{
    SqratVM vm1;
    SqratVM vm2;
    
    bind(vm1.getVM());
    bind(vm2.getVM());
    
}