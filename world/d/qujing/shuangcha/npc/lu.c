//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.3
//  /d/qujing/shuangcha/npc/lu.c


inherit NPC;

void create()
{
   set_name("梅花鹿", ({ "meihua lu" }) );
   set("race", "野兽");
   set("age", 3);
   set("long", "一只脖子很长的梅花鹿。\n");
   
   set("str", 32);
   set("dex", 36);

   set("limbs", ({ "头部", "身体", "前脚", "后脚", "脖子" }) );
   set("verbs", ({ "bite", "claw" }) );

   set("chat_msg", ({
     (: call_other, this_object(), "random_move" :),
        }));
     
   set_temp("apply/attack", 20);
   set_temp("apply/armor", 10);

   setup();
}

int accept_object(object who, object ob)
{
   if( ob->id("grass") ) {
     set_leader(who);
     message("vision", name() + "很高兴的吃了你给它的草。\n", environment());
     return 1;
   }
}
