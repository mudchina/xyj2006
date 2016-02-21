
inherit COMBINED_ITEM;

void setup()
{}

void init()
{
  add_action("do_eat", "eat");
}

void create()
{
  set_name("济神丸", ({"jishen wan", "wan"}));
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("base_unit", "颗");
    set("unit", "些");
    set("long", "一颗清凉略苦的药丸．\n");
    set("value", 300);
    set("drug_type", "良药");
  }
  set_amount(1);

  setup();
}

int do_eat(string arg)
{
  if (arg != "jishen wan" && arg != "wan")
    return 0;

//  if ((int)this_player()->query("eff_sen") == 
//    (int)this_player()->query("max_sen"))
//    return notify_fail("你现在不需要用济神丸。\n")
  else {
    this_player()->receive_curing("sen", 40+random(10));
    message_vision("$N咽下一颗济神丸，精神焕发。\n",this_player());
   add_amount(-1);
    return 1;
  }
}

