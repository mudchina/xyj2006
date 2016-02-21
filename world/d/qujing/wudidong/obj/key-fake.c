// key.c
// created by mes, updated 6-20-97b pickle

inherit ITEM;

void create()
{
  set_name("铁钥匙", ({ "tie yaoshi","key","iron key", "yaoshi" }));
  set_weight(200);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "一把普普通通的钥匙. \n");
    set("unit", "把");
    set("material", "iron");
    set("no_give", 1);
    set("value", 0);
    set("name_recognized", "fake key");
  }
  setup();
}

void init ()
{
  call_out ("destruct_me",300,this_object());
}

void destruct_me (object me)
{
  destruct (me);
}

