// daya-jian_book.c

//lestat
#include <ansi.h>
inherit ITEM;

void destroy();
void init();
void init()
{
  if (!wizardp(this_player())) {
//    set("no_get","你手里一松"+this_object()->query("name")+"从指间滑落,片片碎去！\n");
    set("no_give","冒生命危险得来的东西，哪能随便给人？\n");
    set("no_drop","这么宝贵的书，扔了多可惜呀！\n");
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  }                                    
    call_out("destroy", 120);
}
void create()
{
        set_name(HIY"大雅古剑谱"NOR, ({ "daya_sword_book", "book" }));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                        "一张薄薄的丝绢,看来有些年代了,上面密密麻麻布满蝇头小楷,右首有五个大字:大雅古剑谱。\n"
                        "看起来随时会碎掉。\n");
                set("value", 0);
                set("material", "paper");
                set("skill", ([
                        "name":        "daya-jian",          // name of the skill
//                        "exp_required": 1000000,                          // minimum combat experience required
                                                                        // to learn this skill.
                        "sen_cost":     30,                             // gin cost every time study this
                        "difficulty":   30,                             // the base int to learn this skill
                                                                        // modify is gin_cost's (difficulty - int)*5%
                        "max_skill":    100,                            // the maximum level you can learn
                        "min_skill":    0                               // the maximum level you can learn
                                                                        // from this object.
                ]) );
        }
}
//int query_autoload() { return 1; }
void destroy()
{
  destruct(this_object());
}

