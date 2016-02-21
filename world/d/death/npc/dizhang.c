
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//puti.c
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string avenge();
string ask_chuxian();
string ask_cancel();
int begin_go();

void create()
{
  set_name("地藏王菩萨", ({"dizang pusa", "pusa"}));
  set("long", "面如朱玉，大耳垂肩，一脸肃静．
他便是主管阴曹地府，天下鬼魂的地藏王菩萨．\n");
  set("gender", "男性");
  set("class", "youling");
  set("age", 70);
  set("attitude", "friendly");
  set("shen_type", 1);
  set("per", 30);
  set("str", 30);
  set("int", 30+random(5));
  set("nkgain",790);
  set("max_kee", 3000);
  set("max_gin", 2500);
  set("max_sen", 2000);

  set("force", 4500);
  set("max_force", 4000);
  set("force_factor", 200);
  set("max_mana", 5500);
  set("mana", 8000);
  set("mana_factor", 200);

  set("combat_exp", 2000000);

//   set_skill("unarmed", 150);
   set_skill("unarmed", 200);
  set_skill("whip", 200);
  set_skill("hellfire-whip", 200);
  set_skill("dodge", 200);
//   set_skill("parry", 150);
   set_skill("parry", 200);
//   set_skill("literate", 130);
   set_skill("literate", 200);
//   set_skill("spells", 180);
   set_skill("spells", 200);
  set_skill("force", 200);
//  set_skill("tonsillit", 180);
  set_skill("tonsillit", 200);
  set_skill("ghost-steps", 200);
//     set_skill("gouhunshu", 190);
     set_skill("gouhunshu", 200);
//   set_skill("jinghun-zhang", 150);
   set_skill("jinghun-zhang", 200);
  set_skill("kusang-bang", 200);
   set_skill("zhuihun-sword", 200);
   set_skill("sword", 200);
   set_skill("stick", 200);

  map_skill("force", "tonsillit");
  map_skill("unarmed", "jinghun-zhang");
  map_skill("dodge", "ghost-steps");
  map_skill("spells", "gouhunshu");
  map_skill("parry", "hellfire-whip");
  map_skill("whip", "hellfire-whip");
   map_skill("sword", "zhuihun-sword");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "whip.three" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
                (: cast_spell, "gouhun" :),
        }) );
  set("nk_gain", 600);
set("inquiry",([
  "招魂": (: ask_chuxian :),
  "灵台观礼": (: begin_go :),
  "cancel": (: ask_cancel :),
  "复仇": (: avenge :) ]));
   
  set_temp("apply/armor", 50);
  set_temp("apply/dodge", 50);

  
  create_family("阎罗地府", 1, "你好");
  setup();
  
  carry_object("/d/obj/cloth/baipao")->wear();
  carry_object("/d/obj/weapon/whip/longsuo")->wield();
}

string avenge()
{
    object who=this_player(),killer,where;
    string killid;
    if((string)who->query("family/family_name")!="阎罗地府")
        return ("你不是本派弟子，生死与本王何干？");
    if(who->query("faith")<1000)
        return ("你在本门名望还不够，还需多加努力才行。");
    if(who->query("avenge/mud_age")>=who->query("death/mud_age"))
        return ("本王未闻死讯");
    killid=who->query("kill/last_killer");
    killer=find_living(killid);
    if(!killer||!userp(killer))
        return ("这个嘛，本王还得想一想");
    command("say 本王这就去为你抱仇。");
    who->set("avenge/mud_age",who->query("mud_age"));
    where=environment(who);
    tell_room(where,"只见地藏王菩萨向空中一指：\n");
    tell_room(where,"索魂小鬼何在，速去将"+killer->query("name")+"抓来。\n")
;
    tell_room(environment(killer),"空中伸出一只大手将"+killer->query("name")
+"抓了起来！");
    killer->move(where);
    tell_room(where,killer->query("name")+"被从空中扔了下来。\n");
    command("say 大胆妖孽，胆敢杀害我阎罗地府弟子");
    this_object()->kill_ob(killer);
    return("拿命来。");
}  
void attempt_apprentice(object ob, object me)
{
  if ( (string)ob->query("family/family_name")=="阎罗地府") {
    if (((int)ob->query("combat_exp") < 350000 )) {
      command("say " + RANK_D->query_rude(ob) + "这点三脚猫的把式也敢到我这里丢人现眼？");
      return;
    }
    command("grin");
    command("say 很好，" + RANK_D->query_respect(ob) +
       "多加努力，他日必定有成。\n");
    command("recruit " + ob->query("id") );
    return;
  }
  command("shake");
  command("say " + RANK_D->query_respect(ob) +
     "还是先去学些基础功夫吧！\n");
  return;
}

string ask_chuxian()
{
  object me=this_player();
  if(me->query("family/family_name")!="阎罗地府")
     return ("你不是本门中人！");
  
  command("smile "+me->query("id"));
  return "/d/obj/mieyao"->query_yao(me);
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

int begin_go()
{
	object me,ob;
   	int dx,dx1,wx,qn;
    me=this_player();
	ob=this_object();
	dx=(me->query("daoxing"))/20;
if (dx>=100000) dx=100000;
	dx1=dx/1000;
	wx=(me->query("combat_exp"))/20;
if (wx>=10000) wx=10000;
	qn=30000;
    if (!me->query("fangcun/panlong_visite"))
	  return 0;
    if (me->query("guanli/hell"))
	  return 0;

		if (me->query("fangcun/panlong_hell")=="done")
	{
        message_vision("\n地藏王菩萨道：" + RANK_D->query_respect(me) + "本座即刻赴灵台之约！\n"NOR,me);
        message_vision(HIC"\n只见地藏王菩萨脚低冒上来一股青气,刹时间便不见了！\n"NOR,me);
    	ob->move("/d/lingtai/inside1");
		return 1;
	}

    if ((me->query("fangcun/panlong_hell_18")=="done")&&(me->query("fangcun/panlong_hell_longjin")=="done"))
	{
		me->add("fangcun/panlong_visite",1);
		me->set("fangcun/panlong_hell","done");
        me->delete("fangcun/panlong_hell_18");
        me->delete("fangcun/panlong_hell_longjin");
    message("chat",HIC+"〖"+HIW+"西游记2006"+HIC+"〗地藏王菩萨(Dizang pusa)："+me->query("name")+ RANK_D->query_respect(me) +"闯过我幽冥地府十八层地狱，寻得龙筋，当真后生可畏！\n"NOR,users());
                 message("chat",HIC+"〖"+HIW+"西游记2006"+HIC+"〗地藏王菩萨(Dizang pusa)："+me->query("name")+"得到奖励：道行"+chinese_number(dx1)+"年，武学"+wx+"点，潜能30000点．\n"NOR,users());
   	    if (me->query("family/family_name")=="方寸山三星洞")
    		message_vision("\n\n地藏王菩萨道：他日还望" + RANK_D->query_respect(me) + "前来通知本座一声.\n"NOR,me);
		me->add("daoxing",dx);
		me->add("combat_exp",wx);
		me->add("potential",30000);
	    if ((me->query("family/family_name")!="方寸山三星洞")||(me->query("fangcun/panlong_noway")))
			me->set("guanli/hell",1);
		return 1;
	}

			if ((me->query("fangcun/panlong_hell_18")=="done")&&(me->query("fangcun/panlong_hell_longjin")=="begin"))
	{
    		  command("say " + RANK_D->query_respect(me) + "可曾寻来恶龙龙筋？\n");
			  return 1;
	}
	        if (me->query("fangcun/panlong_hell_18")=="done")
	        {
        		  command("say " + RANK_D->query_respect(me) + "好武功，只是这近些日子来本座兵器越来越不称手，若是" + RANK_D->query_respect(me) + "能再为本座
                寻得"+HIY"龙筋"+NOR""+CYN"来，待我制成缚龙索，本座便随你去灵台。\n");
				  me->set("fangcun/panlong_hell_longjin","begin");
				  me->set("fangcun/panlong_nowayhell",1);
                  return 1;
			}

			if ((me->query("fangcun/panlong_hell_18")!="begin")&&(me->query("fangcun/panlong_visite")))
    {
  command("say 人言近来后生可畏，不知" + RANK_D->query_respect(me) + "你到底有何能耐，如能闯过我冥府十八层地狱再作打算不迟．\n");
   me->set("fangcun/panlong_hell_18","begin");
	return 1;
	}
  command("say 怎么，" + RANK_D->query_respect(me) + "未能闯过那十八层地狱？\n");
  command("sigh ");

  return 1;
}

int accept_object(object me, object ob)
{
   if ((me->query("fangcun/panlong_hell_18")=="done")&&(me->query("fangcun/panlong_hell_longjin")=="begin"))
	{	 
	 if (ob->query("id") == "ruan longjin")
	{
	 command ("nod "+me->query("id"));
     command ("say 好，好，本座要的正是这个。有劳"+me->query("name")+ RANK_D->query_respect(me) +"了！\n\n");
     me->set("fangcun/panlong_hell_longjin","done");
	 if (ob->query_temp("iambaddragon"))
     	 me->delete("fangcun/panlong_nowayhell");
      call_out("destroy", 1, ob);
      return 1;
	}
	}
return 0;
}

void destroy(object ob)
{
  destruct(ob);
}
