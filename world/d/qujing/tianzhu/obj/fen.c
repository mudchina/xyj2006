
inherit COMBINED_ITEM;

void setup()
{}

void init()
{
  add_action("do_eat", "eat");
}

void create()
{
  set_name("筋骨粉", ({"jingu fen", "fen"}));
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("base_unit", "包");
    set("unit", "些");
    set("long", "一包灰土色的药粉。\n");
    set("value", 300);
    set("drug_type", "良药");
  }
  set_amount(1);
  setup();
}

int do_eat(string arg)
{
  if (arg != "jingu fen" && arg != "fen")
    return 0;

//  if ((int)this_player()->query("eff_kee") == 
//    (int)this_player()->query("max_kee"))
//    return notify_fail("你现在不需要用筋骨粉。\n")
  else {
    this_player()->receive_curing("kee", 40+random(10));
    message_vision("$N咽下一包筋骨粉，顿时出了一身热汗。\n",this_player());
    add_amount(-1);
    return 1;
  }
}

