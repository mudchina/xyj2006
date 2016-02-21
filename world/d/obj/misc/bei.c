//create by guoth

#include <ansi.h>

inherit ITEM;

void create()
{
   set_name( HIG "※"+HIC+"巫师纪念碑"+HIG+"※" NOR , ({ "jinian bei" }) );
   set_weight(200000);
   set("long", @LONG
这是为仙侣情缘的创世英雄们树立的纪念碑
以下是他们的名字：

            ☆: 神    龙 (  cnd  )
            ☆: 游戏兔子 ( guoth )
            ☆: 一叶知秋 ( vikee )
            ☆: 雨    点 (yudian )
            ☆: 八 大 王 ( caoji )
            ☆: 绿 无 常 (greenwc)
            ☆: 红    豆 (hongdou)

         希望您也能成为里边其中的一员
LONG);
       if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "座");
                set("material", "stone");
                set("value", 2000);
                set("no_get", 1);
                set("amount",30);
        }
 
            setup();
}

