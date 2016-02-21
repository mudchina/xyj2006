// by snowcat oct 24 1997

inherit NPC;

void create()
{
  set_name("说书老", ({"shuoshu lao", "lao"}) );
  set("gender", "男性" );
  set("age", 55);
  set("long","一位口若悬河的老人，正在敲木说书。\n");

  set("combat_exp", 5500);
  set("str", 25);
  set("attitude","heroism");

  setup();
  carry_object("/d/qujing/chechi/obj/changpao")->wear();
  add_money("silver", 2);
}

void init()
{
  remove_call_out ("says");
  call_out("says",random(3),this_object());
}

void says (object me)
{
  string *msgs = ({
    "$N“啪”地拍了一下惊堂木。\n",
    "$N绘声绘色地说着什么。\n",
    "$N滔滔不绝地说着书。\n",
    "$N说得眉飞色舞。\n",
    "$N卖了个关子，停下不说了。\n",
    "$N端起碗喝了几口水，又说开了。\n",
  });
  message_vision (msgs[random(sizeof(msgs))],me);
  remove_call_out ("says");
  if(sizeof(filter_array(all_inventory(environment(this_object())), (:userp:))))
  call_out("says",random(40),me);
}

