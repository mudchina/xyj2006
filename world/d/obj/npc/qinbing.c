
#include <ansi.h>
inherit NPC;
void create()
{
   set_name("九天神将", ({ "qinbing" }) );
   set("long","具有极高法力的护法天神.\n");
   set("attitude", "friendly");
   set("class", "fighter");

   set("max_gin", 500);
    set("max_kee", 500);
   set("max_sen", 500);
   set("max_force", 500);
   set("force", 500);
   set("force_factor",10);

   set("max_mana",200);
   set("mana",300);
   set("mana_factor",10);
   set("str", 40);
   set("cor", 30);
   set("cps", 25);
   set("per", 10+random(15));

   set("combat_exp", 50000);
   set_skill("parry",150);
   set_skill("dodge", 140);
   set_skill("yanxing-steps",150);
   set_skill("spells", 150);
   set_skill("dao",160);
   set_skill("unarmed",150);
   set_skill("changquan", 150);
   set_skill("spear",150);
   set_skill("bawang-qiang", 150);
   map_skill("unarmed", "changquan");
   map_skill("dodge", "yanxing-steps");
   map_skill("spear", "bawang-qiang");
   map_skill("spells", "dao");

   set("chat_msg_combat",({
   (: cast_spell, "light" :),
}));
   setup
();

   carry_object("/d/obj/armor/yinjia")->wear();
   carry_object("/d/obj/weapon/spear/jinqiang")->wield();
}

void leave()
{
   message("vision", name() + "四周张望了一下，一溜烟地跑了。\n", environment(),
 this_object() );
   destruct(this_object());
}

void show(object who)
{
   string *cname = ({"修罗王","龙王","伽偻罗王","夜叉王"});
   string *ename = ({"-jia", "-yi", "-bing", "-ding"});

   int current = 0;

   current = (int)who->query_temp("jjf_current_bing");
   if(current < 1 || current > 4 )
   {
     destruct(this_object());
     return;
   }


   this_object()->set_name(cname[current-1], ({ (string)who->query("id")+ename[current-1] }) );

   message_vision(HIY"天空降下一道金光,一个长相奇特的护法从金光中走出.\n"NOR, who);

    //set the leader of this bing.
   set("owner_id", (string)who->query("id"));
   set_leader(who);
}

void relay_whisper(object me, string msg)
{
   if (query("owner_id") != me->query("id"))
   {

     message_vision((string)this_object()->query("name")
        + "对着$N冷哼了一声。\n", me);
     return;
   }

   //note, do not allow the order contain "chat", "tell"...
   //may need disable more later...
   if( strsrch(msg, "chat") != -1 ||
       strsrch(msg, "tell") != -1 ||
       strsrch(msg, "apprentice") != -1 ||
       strsrch(msg, "recruit") != -1 )
     return;

   message_vision((string)this_object()->query("name") + "对着$N点了点头。\n", me);
   if (msg)
   {
     remove_call_out ("relaying");
     call_out ("relaying", 1+random(3), msg);
   }
}

void relaying (string msg)
{//execute the order.
   command (msg);
}
void init()
{
   object me=this_player();
   object owner;

   ::init();

   //make sure this bing always follow his owner.
   if ( (string)this_object()->query("owner_id") == (string)me->query("id") )
   {
     this_object()->set_leader(me);
   }

   //if owner leaves, let this bing have chance to disappear.
   if( this_object()->query("owner_id") != 0 )
   {
     owner = find_player( (string)this_object()->query("owner_id") );
     if( !owner ) owner=find_living( (string)this_object()->query("owner_id") );
     if( !owner )
     {
        remove_call_out ("leave");
        call_out ("leave", 1);
     }
   }

}
