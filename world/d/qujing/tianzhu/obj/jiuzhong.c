inherit ITEM;
inherit F_LIQUID;

void create()
{
  set_name("瓷酒盅", ({"jiu zhong", "jiuzhong", "zhong"}));
  set_weight(800);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
     set("long", "一个盛热酒的瓷酒盅。\n");
     set("unit", "个");
     set("value", 70);
     set("max_liquid", 5);
  }

  set("liquid", ([
        "type": "alcohol",
        "name": "热酒",
        "remaining": 7,
        "drunk_apply": 8,
      ]));
}

