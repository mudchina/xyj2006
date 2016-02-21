//Cracked by Roath
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// dog.c

inherit NPC;

void create()
{
   set_name("大狼狗", ({ "dog" }) );
   set("race", "野兽");
   set("age", 3);
   set("long", "一只长得很凶猛的狼狗。\n");
   
   set("str", 32);
   set("dex", 36);

   set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
   set("verbs", ({ "bite", "claw" }) );

   set("chat_chance", 6);
   set("chat_msg", ({
     (: call_other, this_object(), "random_move" :),
     "大狼狗朝你汪汪乱叫。\n",
     "大狼狗用后腿抓了抓自己的耳朵。\n" }) );
     
   set_temp("apply/attack", 10);
   set_temp("apply/armor", 3);

   setup();
}

int accept_object(object who, object ob)
{
   if( ob->id("bone") ) {
     set_leader(who);
     message("vision", name() + "高兴地汪汪叫了起来。\n", environment());
     return 1;
   }
}
