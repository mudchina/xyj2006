#include <ansi.h> 

inherit ITEM;

void create()
{
        set_name(HIW"信"NOR, ({"letter", "xin"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long",
"这是张以天蚕洁丝所织的信纸，上面李逍遥仓促间写下的几行字：\n"
"\n"

"         言出必行，乃丈夫也！急人之难，纵有千险亦置之\n" 
"     度外大侠也！灵儿我已救出，逍遥不敢先行，无奈灵儿\n" 
"     伤势刻不容缓，特留下我蜀山灵符一张，ｂａｃｋ便可\n" 
"     脱离险地．　　　　　　　　　　　　　　　　　　　　　\n"
"\n"
"                                             逍遥顿首\n");
                set("material", "paper");
        }
  setup();
}
