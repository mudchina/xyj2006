// by mind
#include <ansi.h>

inherit ITEM;

string *prefixs = ({
  HIR"冲天"NOR,
  HIG"拐子"NOR,
  HIY"筋斗"NOR,
  HIC"霹雳"NOR,
});

string *names = ({
  HIB"双响"NOR,
  HIM"流星"NOR,
  MAG"风雷"NOR,
});

string *suffixs = ({
  HIW"鞭炮"NOR,
  RED"焰炮"NOR,
});

void create()
{
  set_name(prefixs[random(sizeof(prefixs))]+names[random(sizeof(names))]+
           suffixs[random(sizeof(suffixs))], ({"bian pao", "pao", "bomb"}));
  set_weight(5000);
        set("explosive",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "大唐黎民过年时候经常燃放的烟炮，有的威力还蛮大的。\n");
        }

  setup();
}
