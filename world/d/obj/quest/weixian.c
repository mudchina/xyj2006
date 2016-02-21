//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include <task.h>
void create()
{
    set_name("味仙认证", ({ "weixian" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "cloth");
            set("long", "这是朝廷御赐的一本民间厨子最高荣誉证书\n");
            set("owner_name", "万口福");
          set("owner_id", "wan koufu");
          }

    setup();
}
