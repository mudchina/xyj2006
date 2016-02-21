inherit NPC;

inherit F_VENDOR;

void create()
{
     set_name("火麒麟",({"sheying shi","sheyingshi","shi","火麒麟"}));
     set("title","摄影师");
     set("gender","男性");
     set("age",22);
     set("per",30);
     set("long","这位摄影师的来历非常神秘,但是看起来充满了艺术家的气质。\n");
     set("combat",10000);
     set_skill("unarmed",50);
   set("no_accept",0);
     set("attitude","friendly");
     setup();


     carry_object("/d/obj/cloth/choupao")->wear();
     carry_object("/obj/toy/camera");
     add_money("gold",10);
}

void init()
{
     object ob,me;
     me=this_object();
     ::init();
     if( interactive(ob = this_player()) && !is_fighting() ) {
            remove_call_out("greeting");
            call_out("greeting", 1, ob);
     }
}

void greeting(object ob)
{

     switch( random(3) ) {
     case 0:
            say("火麒麟走过来，微笑着说道：这位" +
RANK_D->query_respect(ob)
             + "，来照张相,留个纪念吧。\n",this_object());
            break;
     case 1:
            say("火麒麟不知道在看什么,有人进来了也没有反应。\n",this_object());
            break;
     case 2:
            say("火麒麟见到有人进来，立刻放下手中的相机，热情地打招呼。\n",this_object());
            break;
     }
}

int accept_object(object me,object ob)
{
   me=this_player();
   ob=this_object();


   if ((string)ob->query("name")=="摄魂匣"
       && (string)ob->query("id")=="camera")
   {
     command("thank" + me->query("id"));
     command("bow");
     return 1;
   }
   return 0;
}

