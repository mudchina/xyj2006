//Cracked by Roath
#include <ansi.h>
inherit ITEM;
void create()
{
set_name(HIW "水灵珠" NOR, ({"shui lingzhu"}) );
 set_weight(200);
        if( clonep() )
  set_default_object(__FILE__);
 else {
  set("unit", "颗");
  set("material", "crystal");
  set("value",1);
  set("long","传说中的五行宝珠之一，佩之可避水淹，并可发出水系法术。\n为祈雨
所必需之物。");
                set("owner_name","观音菩萨");
                set("owner_id","guanyin pusa");
}
 setup();
}
