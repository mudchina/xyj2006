// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// pao.c

inherit EQUIP;

void create()
{
          set_name("皂罗袍", ({"zaoluo pao", "pao", "cloth"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 2000);
                set("material", "cloth");
                set("armor_type", "cloth");
                set("armor_prop/armor", 10);
                set("armor_prop/dodge", 5);
                set("armor_prop/spells", 5);
             }
}

