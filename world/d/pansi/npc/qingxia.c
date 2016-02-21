
//zixiaxianzi.c 2001 by lestat
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_mieyao();
string ask_cancel();
string avenge();
string give_zui(object me);
void create()
{
       set_name(MAG"青霞仙子"NOR, ({"qingxia xianzi", "qingxia", "xianzi","master"}));
       set("long", "她是紫霞仙子的孪生姐姐,曾被佛祖把她和紫霞仙子捏在一棵灯芯里。後因紫霞仙子思凡
下界开山立派,故追至此处。\n");
       set("title", HIY"佛祖灯芯"NOR);
       set("gender", "女性");
       set("age", 20);
       set("class","yaomo");
       set("attitude", "friendly");
       set("rank_info/respect", "小姑娘");
       set("cor", 30);
       set("per", 21);
       set("max_kee", 4500);
       set("max_gin", 800);
       set("max_sen", 4500);
       set("force", 4000);
       set("max_force", 2400);
       set("force_factor", 125);
       set("max_mana", 1800);
       set("mana", 3000);
       set("mana_factor", 150);
       set("combat_exp", 1600000);
	   set("daoxing", 3000000);
       set_skill("literate", 150);
       set_skill("unarmed", 180);
       set_skill("dodge", 160);
       set_skill("force", 160);
       set_skill("parry", 150);
       set_skill("sword", 180);
       set_skill("spells", 150);
       set_skill("whip", 180);
   set_skill("pansi-dafa", 160);
   set_skill("lanhua-shou", 160);
   set_skill("jiuyin-xinjing", 150);
   set_skill("qingxia-jian", 200);
   set_skill("yueying-wubu", 150);
   set_skill("yinsuo-jinling", 150);
   map_skill("spells", "pansi-dafa");
   map_skill("unarmed", "lanhua-shou");
   map_skill("force", "jiuyin-xinjing");
   map_skill("sword", "qingxia-jian");
   map_skill("parry", "yinsuo-jinling");
   map_skill("dodge", "yueying-wubu");
   map_skill("whip", "yinsuo-jinling");
   set("chat_chance_combat", 50);
   set("inquiry", ([
          "复仇" : (: avenge :),
          "紫霞" : "我就是来找那个贱人算账的.",
    	  "紫霞仙子" : "我就是来找那个贱人算账的.",
//		  "醉生梦死" : (: give_zui :),
           "修炼": (: ask_mieyao :),
           "cancel": (: ask_cancel :),
]));
   set("no_zui", 0);
create_family("盘丝洞", 1, "红");
setup();

        carry_object("/d/obj/cloth/tianyi.c")->wear();
        carry_object("/d/obj/weapon/sword/qinghong")->wield();
        carry_object("/d/ourhome/obj/shoes")->wear();
}
void init()
{
add_action("do_kneel","kneel");
add_action("do_yes", "yes");
}
string avenge()
{
    object who=this_player(),killer,where;
    string killid;
    if((string)who->query("family/family_name")!="盘丝洞")
        return ("你不是本派弟子，生死与我何干？");
    if(who->query("faith")<1000)
        return ("你在本门名望还不够，还需多加努力才行。");
    if(who->query("avenge/mud_age")>=who->query("death/mud_age"))
        return ("本座未闻死讯");
    killid=who->query("kill/last_killer");
    killer=find_living(killid);
    if(!killer||!userp(killer))
        return ("这个嘛，本座还得想一想");
    command("say 本座这就去为你抱仇。");
    who->set("avenge/mud_age",who->query("mud_age"));
    where=environment(who);
    tell_room(where,"只见青霞仙子向空中一指：\n");
    tell_room(where,"护法天尊何在，速去将"+killer->query("name")+"抓来。\n");
    tell_room(environment(killer),"空中伸出一只大手将"+killer->query("name")+"抓走了。\n");
    killer->move(where);
    tell_room(where,killer->query("name")+"被从空中扔了下来。\n");
    command("say 孽障，胆敢杀害我盘丝洞弟子");
    this_object()->kill_ob(killer);
    return("拿命来。");
} 
void attempt_apprentice(object ob)
{
   /*if ( !((string)ob->query("gender")=="女性")){
      command("shake");
          command("say 我们盘丝洞只收女徒，这位" + RANK_D->query_respect(ob) + "还是另请高就吧。\n");
      return;
   }*/

   if ( (string)ob->query("family/family_name")=="盘丝洞") {
   if (((int)ob->query("daoxing") < 500000 )) {
   command("say " + RANK_D->query_respect(ob) +
"的道行不够高深，有些绝学秘法恐怕难以领悟。\n");
   return;
   }
        command("pat "+ob->query("id"));
        command("say 好，希望" + RANK_D->query_respect(ob) +
"多加努力，把我们盘丝洞发扬光大。\n");
       command("recruit " + ob->query("id") );
	   ob->set("title", "盘丝洞青霞仙子传人");
           ob->set("class", "yaomo");
   return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) +
"还是先去学些基础功夫吧。\n");
        return;
}
int accept_fight(object me)
{
   return 0;
}

string ask_mieyao()
{
    object who=this_player();

    if((string)who->query("family/family_name")=="盘丝洞") {
      command("smile "+who->query("id"));
      return "/d/obj/mieyao"->query_yao(who);
    }
    return ("非我门人,何故来此?\n");
}
int do_kneel()
{
    object who = this_player();
    if((string)who->query("family/family_name")!="盘丝洞")
     return notify_fail(this_object()->query("name")+"说：你又不是我座下弟子，拜我干什么？\n");
   if("/d/obj/mieyao"->delete_mieyao(who)){
        command("say 既然如此，就算了吧，不过你没有完成任务，得受些惩罚！\n");
	who->add("faith",-5);
        message_vision("$N的忠诚度下降了！\n",who);
     }
}

string ask_cancel()
{
    object me=this_player();
if((int)me->query_temp("m_mieyao"))
{
      me->add("daoxing",-2000);
      me->delete_temp("m_mieyao");
      me->delete("secmieyao");
      me->delete("secmieyao/type");
      me->delete("secmieyao/location");
      me->delete("secmieyao/place");
      me->delete("secmieyao/name");
      me->delete("secmieyao/id");
     return ("没用的东西！");
}
else
{
     return ("你有任务吗？！");
}
}

void destroy(object ob)
{
        destruct(ob);
        return;
}

void dropthing(string thing)
{
  command("drop "+thing);
  return;
}
int accept_object(object me,object ob)
{       
	    string myname=RANK_D->query_respect(me), thing=(string)ob->query("id");
		object who;
        who=this_object();
  if (me->query("fangcun/panlong_pansi")=="begin")
	{
	  if ((ob->query("id") == "yinsuo jinling")&&(ob->query_temp("zixia_xianzi")))
      {
      command ("sigh");
//	  me->set_temp("qingxia_xianzi","give");
      message_vision(MAG"\n\n青霞仙子"+HIY"正想说些什么，突然狂风大作，刹那间飞沙走石，吹的人睁不开眼睛．\n"NOR,me);
      call_out("destroy", 1, ob);
	  call_out("tianbing_come",3,me,who);
      return 1;
	  }
	  command ("say 这是什么？");
      call_out("dropthing", 1, thing);
      return 1;
    }
  command ("shake ");
  return 0;
}

void tianbing_come(object me,object ob)
{
   object erlang,dog;
   erlang=new("/d/pansi/npc/erlangshen");
   dog=new("/d/pansi/npc/dog");
   message_vision(NOR"\n\n只见"+HIY"二郎神"+NOR"手持三尖两刃枪，带着"+HIY"啸天犬"+NOR"杀气腾腾的朝"+MAG"青霞仙子"+NOR"而来．\n"NOR,me);
   me->set("fangcun/panlong_nowaypansi",1);
   me->set_temp("give_suo",1);
   me->delete("fangcun/panlong_pansi");
   erlang->move(environment(me));
   erlang->set_temp("killer_me",1);
   erlang->set("killer","zixia xianzi");
   dog->move(environment(me));
   dog->set_temp("killer_me",1);
   message_vision(HIY"\n\n$N手中三尖两刃枪一抖，大喝道：青霞，你和你妹妹紫霞私逃下界，触犯天条，今日我就替如来
   　　　　　　　　　　　　         佛祖除掉你以示天威，受死吧．\n"NOR, erlang);
   call_out("zixia_out",3,me);
}

void zixia_out(object me)
{
	object zixia;
	zixia=new("/d/pansi/npc/zixia");
	zixia->move(environment(me));
      message_vision("\n\n杨戬正待动手之际，突然从瀑布下飘上来一个身影，$N定睛一看原来是紫霞仙子．\n"NOR,me);
      message_vision(MAG"\n\n\n青霞冷笑一声道：哼，你来干什么，送死吗？\n"NOR,me);
      message_vision(HIM"\n\n\n紫霞仙子道：姐姐你快走，几千年了，我不想再斗了．我．．．．我就你这么一个姐姐．\n"NOR,me);
      message_vision(MAG"\n\n青霞仙子：．．．．．．\n\n"NOR,me);
	  call_out("fight_erlang",5,me);
}

void fight_erlang(object me)
{
     
	message_vision("\n\n\n"+HIM"紫霞仙子"+NOR"荡开腕上的银索金铃"+MAG"青霞仙子"+NOR"一摆手中青虹剑，一同攻向杨戬．\n"NOR,me);
     message_vision(HIY"\n\n\n杨戬哈哈大笑道：来的正好，两个一起拿下了．\n"NOR,me);
     message_vision(HIY"\n\n\n杨戬对着$N道：我奉玉帝旨意前来拿人，尔等胆敢抗旨不尊者，格杀勿论．\n\n\n"NOR,me);
    call_out("fightings",2,me);
}

void fightings(object me)
{
	object erlang,dog,zixia,qingxia;
	 erlang=present("erlang zhenjun",environment(me));
	 dog=present("xiaotian quan",environment(me));
	 qingxia=present("qingxia xianzi",environment(me));
	 zixia=present("zixia xianzi",environment(me));
	     erlang->kill_ob(qingxia);
	 erlang->kill_ob(zixia);
	 dog->kill_ob(qingxia);
	 dog->kill_ob(zixia);
}


void die()
{
	object zixia,erlang;
	object me=this_object();
    zixia=present("zixia xianzi");
	erlang=present("erlang zhenjun");
   if (!erlang)
	   return ::die();
   if (!zixia)
	{
	   message_vision(HIY"\n\n\n杨戬从额上第三只眼中射出一道金光，"+MAG"青霞"+HIY"重伤之下躲避不及被打回原形，化作一根灯芯跳进杨戬的掌中．\n"NOR,me);
	  message_vision(HIY"\n\n\n二郎神哈哈大笑道：区区两根灯芯也敢跟我"+HIR"昭惠灵显王"+HIY"动手，真是不自量力．\n"NOR,me);
	  message_vision("\n\n\n言毕驾一阵狂风大笑而去．\n"NOR,me);
      destruct(erlang);
	  if (present("xiaotian quan"))
        {    
            message("sound", "\n\n啸天犬也紧跟着二郎神扬长而去．\n\n", environment());
            destruct(present("xiaotian quan"));
        }
      destruct(me);
	  return;
	}
	   message_vision(HIY"\n\n\n杨戬从额上第三只眼中射出一道金光，"+MAG"青霞"+HIY"重伤之下躲避不及被打回原形，化作一根灯芯跳进杨戬的掌中．\n\n\n"NOR,me);
      destruct(me);
}
