
inherit ITEM;

void create()
{
  set_name("金灯缸", ({"jindeng gang", "gang"}));
  set_weight(5000000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一个装着酥合香油的大缸，里面有四十九根大灯马。\n");
    set("unit", "个");
  }
}

void init ()
{
  remove_call_out ("burning");
  if(userp(this_player()))
  call_out ("burning",random(30)+1);
}

void burning ()
{
  object where = environment(this_object());
  string *msgs = ({
    "金灯缸里灯火一闪。\n",
    "金灯缸里的灯火被风一吹，跳了一下。\n",
    "灯火闪了一闪。\n",
    "灯火在缸里跳了一下。\n",
  });
  tell_room (where,msgs[random(sizeof(msgs))]); 
  remove_call_out ("burning");
  if(sizeof(filter_array(all_inventory(environment(this_object())), (:userp:))))
  call_out ("burning",random(60)+1);
}
