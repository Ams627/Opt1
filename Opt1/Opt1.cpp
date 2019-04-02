#include "stdafx.h"

bool UseString(char*s)
{
    //printf(s);
    return true;
}

#pragma section("mystuff", read)
#pragma comment(linker, "/include:?UseString@@YA_NPAD@Z")
#pragma comment(linker, "/include:?GetName@X@@SA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ")
#pragma comment(linker, "/include:?swonk@?1??GetName@X@@SA?AV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@XZ@4US@?1??12@SA?AV34@XZ@A")
#define ADDSTATIC(name, tag) static std::string GetName() {\
struct S { \
    char t1[sizeof(tag)]; \
    char t2[sizeof(name)]; \
};\
__declspec(allocate("mystuff")) static S swonk = { tag, name };\
UseString(swonk.t1);\
return name;\
}

class X {
public:
    ADDSTATIC("fred", "jim");
    X()
    {
        printf("Hello");
    }
};

int main()
{
    auto x = new X();
    std::cout << X::GetName() << "\n";
}
