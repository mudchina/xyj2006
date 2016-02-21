//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
    set_name("暗杀宝录", ({ "ansha baolu", "snshabaolu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "张");
            set("material", "paper");
            set("long", "一张记载了江湖有头有脸人物的暗杀黑名单\n");
            set("owner_name", "花忍");
          set("owner_id", "hua ren");
          }
    setup();
}
