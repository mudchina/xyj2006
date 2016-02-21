// 写了好久  by take
#include <skill.h>
#include <ansi.h>


inherit NPC;
inherit F_MASTER;

string expell_me(object me);
int donghai_quest(object who);
string ask_mieyao();
string ask_cancel();
int begin_go();
int begin_yuanshoucheng();


void create()
{
       	set_name("敖广", ({"ao guang", "ao","guang","longwang","wang"}));

	set("long","敖广是东海的龙王，其兄弟分别掌管东，西，南，北四海。
由余其水族众多，声势浩大，俨然独霸一方。\n");
       set("gender", "男性");
       set("age", 66);
	set("title", "东海龙王");
	set("class","dragon");
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("combat_exp", 1260000);
       set("daoxing", 1500000);
       set("rank_info/respect", "陛下");
       set("per", 20);
       set("str", 30);
       set("max_kee", 3000);
       set("max_gin", 400);
       set("max_sen", 1500);
       set("force", 3000);
       set("max_force", 1500);
       set("force_factor", 120);
       set("max_mana", 800);
       set("mana", 1600);
       set("mana_factor", 40);
       set("combat_exp", 1200000);
       set("daoxing", 1500000);
       set_skill("huntian-hammer", 200);
	set_skill("hammer", 200);
	set_skill("literate", 150);
       set_skill("unarmed", 200);
       set_skill("dodge", 200);
       set_skill("force", 200);
       set_skill("parry", 200);
       set_skill("fork", 200);
       set_skill("spells", 200);
	set_skill("seashentong", 200);
	set_skill("dragonfight", 200);
	set_skill("dragonforce", 200);
	set_skill("fengbo-cha", 200);
	set_skill("dragonstep", 200);
	map_skill("hammer", "huntian-hammer");
	map_skill("spells", "seashentong");
	map_skill("unarmed", "dragonfight");
	map_skill("force", "dragonforce");
	map_skill("fork", "fengbo-cha");
	map_skill("parry", "fengbo-cha");
	map_skill("dodge", "dragonstep");
       set("chat_chance_combat", 50);
       set("chat_msg_combat", ({
                (: cast_spell, "hufa" :),
                (: perform_action, "unarmed", "sheshen" :),

                }) );
             set("inquiry", ([ 
           "灵台观礼": (: begin_go :),
           "心事": (: begin_yuanshoucheng :),
           "离宫": (: expell_me :),
	   "leave": (: expell_me :), 
           "灭妖": (: ask_mieyao :),
           "cancel": (: ask_cancel :),
           "兵器": (: donghai_quest :),
           "weapon": (: donghai_quest :), 
        ]) );

        create_family("东海龙宫", 1, "水族");
	set_temp("apply/armor",50);
	set_temp("apply/damage",25);
	setup();

        carry_object("/d/sea/obj/longpao")->wear();
}
void init()
{
	::init();
	add_action("do_agree", "agree");
	add_action("do_learn", "xuexi");
}


void destroy(object ob)
{
        destruct(ob);
        return;
}

void unsetlearn(object ob)
{
	if (find_player(ob->query("id"))) {
		ob->set_temp("temp/learn", 0);
		ob->save();
		}
}


string *reject_msg = ({
	"说道：您太客气了，这怎么敢当？\n",
	"像是受宠若惊一样，说道：请教？这怎么敢当？\n",
	"笑著说道：您见笑了，我这点雕虫小技怎够资格「指点」您什么？\n",
});

int do_learn(string arg)
{
	string skill, teacher, master;
	object me= this_player(), ob;
	int master_skill, my_skill, sen_cost;

	if(!arg || sscanf(arg, "%s from %s", skill, teacher)!=2 )
		return notify_fail("指令格式：xuexi <技能> from <某人>\n");

	if( me->is_fighting() )
		return notify_fail("临阵磨枪？来不及啦。\n");

	if( !(ob = present(teacher, environment(me))) || !ob->is_character())
		return notify_fail("你要向谁求教？\n");

	if( !living(ob) )
		return notify_fail("嗯．．．你得先把" + ob->name() + "弄醒再说。\n");

	if( !master_skill = ob->query_skill(skill, 1) )
		return notify_fail("这项技能你恐怕必须找别人学了。\n");

	if (skill != "unarmed" || !me->query_temp("temp/learn") ) 
		return notify_fail( ob ->name() + reject_msg[random(sizeof(reject_msg))] );

	notify_fail(ob->name() + "不愿意教你这项技能。\n");
	if( ob->prevent_learn(me, skill) )
		return 0;

	my_skill = me->query_skill(skill, 1);
	if( my_skill >= master_skill )
		return notify_fail("这项技能你的程度已经不输你师父了。\n");

	notify_fail("依你目前的能力，没有办法学习这种技能。\n");
	if( !SKILL_D(skill)->valid_learn(me) ) return 0;

	sen_cost = 250 / (int)me->query_int();

	if( !my_skill ) {
		sen_cost *= 2;
		me->set_skill(skill,0);
	}

	if( (int)me->query("learned_points") >= (int)me->query("potential") )
		return notify_fail("你的潜能已经发挥到极限了，没有办法再成长了。\n");
	printf("你向%s虢逃泄亍?s沟囊晌省n", ob->name(),
		to_chinese(skill));

	if( ob->query("env/no_teach") )
		return notify_fail("但是" + ob->name() + "现在并不准备回答你的问题。\n");

	tell_object(ob, sprintf("%s蚰闱虢逃泄亍?s沟奈侍狻n",
		me->name(), to_chinese(skill)));

	if( (int)ob->query("sen") > sen_cost/5 + 1 ) {
		if( userp(ob) ) ob->receive_damage("sen", sen_cost/5 + 1);
	} else {
		write("但是" + ob->name() + "显然太累了，没有办法教你什么。\n");
		tell_object(ob, "但是你太累了，没有办法教" + me->name() + "。\n");
		return 1;
	}
		

	if( (int)me->query("sen") > sen_cost ) {
		if( (string)SKILL_D(skill)->type()=="martial"
		&&	my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) {
			printf("也许是道行不够，你对%s幕卮鹱苁俏薹旎帷n", ob->name() );
		} else {
			printf("你听了%s闹傅迹坪跤行┬牡谩n", ob->name());
			me->add("learned_points", 1);
			me->improve_skill(skill, random(me->query_int()));
		}
	} else {
		sen_cost = me->query("sen");
		write("你今天太累了，结果什么也没有学到。\n");
	}

	me->receive_damage("sen", sen_cost );

	return 1;
}

void attempt_apprentice(object ob)
{	
	if( (int)ob->query_skill("dragonforce",1) < 50
	|| (int)ob->query_skill("seashentong", 1) < 50) {
	command("say " + RANK_D->query_respect(ob) +
		"还是先到大将军或小女处把基础打好了再来我这儿吧。\n");
	return;
	}	
        command("smile");
        command("say 难得" + RANK_D->query_respect(ob) +
		"有此心志，还望日后多加努力，为我东海龙宫争光。\n");
        command("recruit " + ob->query("id") );
	return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "dragon");
}

string expell_me(object me)
{
  me=this_player();
  if((string)me->query("family/family_name")=="东海龙宫")
    {
      me->set_temp("betray", "lg");
      command("sigh");
      return ("你要离开我也不能强留。只是按我东海规矩，却须受罚。
恐怕既是身非龙类，这龙神心法与博击并不能如前般运转，你可愿意(agree)?\n");
    }
  return ("去问问袁先生吧，或许他知道！\n");
}

int do_agree(string arg)
{
  object me;
  me = this_player();
  if(me->query_temp("betray")=="lg")
    {
      message_vision("$N答道：弟子愿意。\n\n", me);
      command("say 人各有志，既是" + RANK_D->query_respect(me) +
        "不愿留在东海，就请出宫去吧。只是江湖险恶，" + RANK_D->query_respect(me) +
	"当好自为之。。。\n");
      me->set_skill("dragonforce", (int)me->query_skill("dragonforce",1)/2);
      me->set_skill("dragonfight", (int)me->query_skill("dragonfight",1)/3);
this_player()->set("combat_exp",this_player()->query("combat_exp")/5*4);
this_player()->set("daoxing",this_player()->query("daoxing")/5*4);
      me->delete("family");
      me->delete("class");
      me->set("title", "普通百姓");
      me->set_temp("betray", 0);
      me->add("betray/count", 1);
      me->add("betray/longgong", 1);
      me->save();
      return 1;
    }
  return 0;
}

int donghai_quest(object who)
{
  object me=this_object();
  object fighter;
  string weapon_name,weapon_id,weapon_unit,temp_flag;

  who=this_player();
  if (who->query("dntg/donghai")=="done") {
    message_vision("$N面色惨淡，不情愿地说：“那神兵还在老地方，且随我来。”\n",this_object());
    call_out("sendto_maze",2,who);
    return 1;
  }

  if (
      who->query("dntg/donghai") == "begin"
      || who->query("dntg/donghai") == "da kan dao"
      || who->query("dntg/donghai") == "jiu gu cha"
      || who->query("dntg/donghai") == "mei hua chui"
     )

    {
        if (who->query("dntg/donghai") == "begin")
           {weapon_name="大砍刀"; weapon_id="da kan dao";weapon_unit="柄";temp_flag="try_dao";}
        if (who->query("dntg/donghai") == "da kan dao")
           {weapon_name="九股叉"; weapon_id="jiu gu cha";weapon_unit="支";temp_flag="try_cha";}
        if (who->query("dntg/donghai") == "jiu gu cha")
           {weapon_name="梅花锤"; weapon_id="mei hua chui";weapon_unit="对";temp_flag="try_chui";}
        if (who->query("dntg/donghai") == "mei hua chui")
           {weapon_name="画杆戟"; weapon_id="hua gan ji";weapon_unit="柄";temp_flag="try_ji";}

        
        if (present(weapon_id, this_player()) && present("ye cha", environment()))
          message_vision("龙王道：您先拿这"+weapon_name+"和夜叉练练吧！\n",me);
        else if (present(weapon_id, environment()) && present("ye cha", environment()))
          message_vision("龙王道：您先拿这"+weapon_name+"和夜叉练练吧！\n",me);
        else if (present(weapon_id, this_player()) || present(weapon_id, environment()))
          {
          message_vision("东海龙王说道：让我找个人先陪您练练？\n",me);
          message_vision("东海龙王一招手，一个夜叉走了过来。\n",me);
          fighter = new ("/d/dntg/donghai/npc/fighter");
          fighter->move(environment(me));
          } 
        else if (present("ye cha", environment()))
          message_vision("龙王道：不知那"+weapon_name+"被谁拿去了！\n",me);
        else
          {
          message_vision("$N连忙起身说道："+RANK_D->query_respect(who)+"稍侯，待我想想？\n",me,who);
          message_vision("我这龙宫中有"+weapon_unit+weapon_name+"还凑合着能使，"+RANK_D->query_respect(who)+"若不嫌弃，就送与"+RANK_D->query_respect(who)+"用吧！\n",who);
          who->set_temp("dntg/donghai",temp_flag);
          call_out ("fight_quest",2,who);
          }
        return 1;
    } 

  else if (who->query("dntg/donghai") == "hua gan ji" )
    {
    me->command("consider");
    message_vision("从后宫跑来一个龙婆，在龙王耳边小声说了几句话。\n",me);
    call_out ("sendto_maze",3,who);
    return 1;
    }
   command("nod");
  message_vision("$N懒洋洋的说：“要兵器啊？傲来国有的是，去那里弄些吧。”\n",me);
  message_vision("$N顿了顿，又说：“我龙宫的兵器，谅你们这些凡夫俗子也使不了。”\n",me);
  command("wave");
  return 1;
}

void fight_quest (object who)
{
  object me=this_object();
  object fighter,fa_bao;
  string weapon_name,weapon_id,weapon_unit;


  if (who->query("dntg/donghai") == "begin")
    {weapon_name="大砍刀"; fa_bao = new ("/d/dntg/donghai/obj/dakandao");weapon_unit="柄";}
  if (who->query("dntg/donghai") == "da kan dao")
    {weapon_name="九股叉"; fa_bao = new ("/d/dntg/donghai/obj/jiugucha");weapon_unit="支";}
  if (who->query("dntg/donghai") == "jiu gu cha")
    {weapon_name="梅花锤"; fa_bao = new ("/d/dntg/donghai/obj/meihuachui");weapon_unit="对";}
  if (who->query("dntg/donghai") == "mei hua chui")
    {weapon_name="画杆戟"; fa_bao = new ("/d/dntg/donghai/obj/huaganji");weapon_unit="柄";}

  message_vision("东海龙王一招手，一个夜叉抬过一"+weapon_unit+weapon_name+"。\n",me);
  fighter = new ("/d/dntg/donghai/npc/fighter");
  fighter->move(environment(me));
  fa_bao->move(environment(me));
  message_vision("东海龙王说道：＂要我要和我的手下先练练？＂\n",me);
}

void sendto_maze (object who)
{
  object me=this_object();
  message_vision("$N说道："+RANK_D->query_respect(who)+"武功盖世，可到后面的海藏中试一试定海神针铁。\n",me,who);
  call_out ("send_maze",3,who);
}

void send_maze (object who)
{
  object me=this_object();
  message_vision("说着，东海龙王把$N送到了一个地方。\n",who);
  who->move("/d/dntg/donghai/haidimigong");
  message_vision("$N一拱手道："+RANK_D->query_respect(who)+"向前走即可看到那神铁，恕老夫不奉陪了。\n",me,who);
  message_vision("说罢，龙王转身回宫了。\n",me);
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
string ask_mieyao()
{
   object me=this_player();
  if(me->query("class")!="dragon")return "你不是本门中人！";
   tell_room(environment(me),"龙王低头想了想。\n");
   return "/d/obj/mieyao"->query_yao(me);
}

void move_lingtai(object me)
{
    message_vision(HIW"\n\n\n不多时竟已来到灵台正院.\n\n"NOR,me);

    me->move("/d/lingtai/inside1");
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
    if (me->query("guanli/longgong"))
	  return 0;

		if (me->query("fangcun/panlong_longgong")=="done")
	{
        message_vision("\n熬广恭身道：" + RANK_D->query_respect(me) + "不必见外,我们这就动身吧！\n"NOR,me);
        message_vision(HIC"\n只见熬广脚低翻上来一股巨浪,托起$N和熬广径直向灵台方向飞去！\n"NOR,me);
		me->start_busy(2);
    	ob->move("/d/lingtai/inside1");
		call_out("move_lingtai",3,me);
		return 1;
	}

    if ((me->query_temp("fangcun/panlong_longgong_longzhu")=="done")&&(me->query_temp("fangcun/panlong_longgong_yuanshoucheng")=="done"))
	{
		me->add("fangcun/panlong_visite",1);
		me->set("fangcun/panlong_longgong","done");
        me->delete_temp("fangcun/panlong_longgong_longzhu");
        me->delete_temp("fangcun/panlong_longgong_yuanshoucheng");
           message("chat",HIC+"〖"+HIW+"西游记2006"+HIC+"〗敖广(Ao guang)："+me->query("name")+"武功高强,见识不凡,观礼之日老龙必亲自前往道贺！\n"NOR,users());
              message("chat",HIC+"〖"+HIW+"西游记2006"+HIC+"〗敖广(Ao guang)："+me->query("name")+"得到奖励：道行"+chinese_number(dx1)+"年，武学"+wx+"点，潜能30000点．\n"NOR,users());
   	    if (me->query("family/family_name")=="方寸山三星洞")
    		message_vision("\n\n敖广道：他日还望" + RANK_D->query_respect(me) + "再来通知老龙一声.\n"NOR,me);
		me->add("daoxing",dx);
		me->add("combat_exp",wx);
		me->add("potential",30000);
	    if ((me->query("family/family_name")!="方寸山三星洞")||(me->query("fangcun/panlong_noway")))
			me->set("guanli/longgong",1);
		return 1;
	}

/*	if (me->query_temp("fangcun/panlong_longgong_longzhu")=="done")
	{
        message_vision("\n敖广道：" + RANK_D->query_respect(me) + "果然武功高强,？\n"NOR,me);
		return 1;
    }
*/ //        搞定 yuanshoucheng 任务
   			if (me->query_temp("fangcun/panlong_longgong_longzhu")=="done")
	{
              command("sigh");
    		  command("say 心事未了，老龙我有何脸面出去见人？\n");
              command("shake");

			  return 1;
	}

			if ((me->query("fangcun/panlong_longgong")!="begin")&&(me->query("fangcun/panlong_visite")))
    {
  command("say 哦，原来" + RANK_D->query_rude(me) + "前来邀请我龙宫赴灵台观礼，叫我老龙走一趟是不难，只是
          不知道" + RANK_D->query_rude(me) + "武功如何？如若" + RANK_D->query_rude(me) + "能战胜我九个不成器的孩儿并将九彩云
	  龙珠带来，我便答应你观礼一事．\n");
   me->set("fangcun/panlong_longgong","begin");
	return 1;
	}
  command("say 怎么，" + RANK_D->query_respect(me) + "连我九个龙子都打不过？\n");
  command("haha ");

  return 1;
}

int accept_object(object me, object ob)
{
  string thing=(string)ob->query("id");

  if (me->query("fangcun/panlong_longgong")=="begin")
  {
           if ((ob->query("id") == "jiucai longzhu")&&(ob->query("name")=="九彩云龙珠")&&(me->query_temp("fangcun/panlong_longgong_longzhu")!="done"))
    {
      command ("ah "+ob->query("id"));
      me->set_temp("fangcun/panlong_longgong_longzhu","done");
//       call_out("destroy", 1, ob);
      message_vision("\n熬广惊道：没想到，" + RANK_D->query_respect(me) + "竟然有一身真本领，前日是老龙失礼了，还望" + RANK_D->query_respect(me) + "莫怪．\n\n\n"NOR,me);
	  message_vision("熬广突然失去了一脸傲然的神色满脸愁容的说道：\n
	  既然" + RANK_D->query_respect(me) + "凭本事取来了九彩云龙珠按理说老龙我也应该即刻随" + RANK_D->query_respect(me) + "去
灵台观礼，只是尚有一"+HIY"心事"+NOR"未了，我东海龙族无颜再见各位仙家同道．\n\n"NOR,me);
	  return 1;
	}
	
 if ((me->query_temp("fangcun/panlong_longgong_yuanshoucheng")=="begin")&&(ob->query("id") == "yuan shoucheng")&&(ob->query("name")=="袁守诚"))
	{
		  command ("great "+me->query("id"));
          me->set_temp("fangcun/panlong_longgong_yuanshoucheng","done");
      	  me->set("fangcun/panlong_nowaylonggong",1);
		  message_vision("熬广大喝道：来人啊，把这个牛鼻子老道给我打入大牢！\n\n"NOR,me);
		  return 1;
	}
 if ((me->query_temp("fangcun/panlong_longgong_yuanshoucheng")=="begin")&&(me->query_temp("help_yuan")=="yes")&&(ob->query("longgong_pass")==1))
	{
    if (!me->query_temp("no_heal_up/bian"))
{
				me->set_temp("fangcun/panlong_longgong_yuanshoucheng","done");
                message_vision("\n\n熬广双手接过"+HIY"金旨"+NOR"，细细读过．．．．．\n\n",me);
				call_out("longgong_done1",2);
				return 1;
}
        if ((me->query_temp("apply/name")[0] == "龟八斗")&&(me->query_temp("apply/id")[0]=="gui badou"))
			{
			  me->set_temp("fangcun/panlong_longgong_yuanshoucheng","done");
                me->add("fangcun/panlong_visite",1);
                message_vision("\n\n熬广双手接过"+HIY"金旨"+NOR"，细细读过．．．．．\n\n",me);
				call_out("longgong_done",2);  
			  return 1;
			}
				
	}
  }

command ("say 这是什么东西？");
return 1;
}

void longgong_done()
{
	object me;
	me=this_player();
    command ("say 这．．．军师的意思是．．．．．．");
    message_vision(WHT"\n$N朗声说道：这泾河龙王虽与大王你同为龙族，但这天道公理不可违，更何况那
　          泾河龙王为逞一时威风与一个算命先生一般见识，竟还违旨不尊，
	    这岂是为仙之道？大王何不三思而后行，切不可落个千古恶名，让
	    世人遗笑！\n"NOR,me);
    message_vision("\n熬广低头沉思．．．\n"NOR,me);
	call_out("longgong_done2",3,me);
}

void longgong_done2(object me)
{
    message_vision("\n老龙王低头沉思良久．．．顷刻间汗如雨下．\n\n"NOR,me);
    command ("say 军师劝阻的对，老龙要杀了那算命之人，岂不背上了这是非不分，黑白不辨的千古恶名？");
    message_vision(WHT"\n\n$N突然间声音一变，哈哈大笑．\n"NOR,me);
    message_vision("\n熬广吃惊不已，倒退两步指着$N喝道：你．．你究竟是何人？\n"NOR,me);
	call_out("longgong_done3",3,me);
}

void longgong_done3(object me)
{
	me->delete_temp("spellslevel");
	me->delete_temp("apply/name");
	me->delete_temp("apply/id");
	me->delete_temp("apply/short");
	me->delete_temp("apply/long");
	me->delete_temp("family");
    me->delete_temp("no_heal_up/bian");
    me->delete_temp("d_mana");
	  while( environment(me)->is_character() )
	     me->move(environment(environment(me)));
          message_vision(HIY "\n\n$N口念咒语，身形一晃，现了真身。\n\n"
	    NOR,me);
    message_vision("\n熬广怒道：原来是你这个" + RANK_D->query_rude(me) + "竟敢戏耍与我？\n\n"NOR,me);
    message_vision(WHT"\n$N急忙抱拳行礼道：龙王误会了，在下如此只为了让龙王明白这些曲折是非，还望龙王三思．\n"NOR,me);
    message_vision("\n\n老龙王又低头沉思良久．．．．\n\n\n\n"NOR,me);
	call_out("longgong_done4",5,me);
}

void longgong_done4(object me)
{
    command ("sigh");
    message_vision("熬广仰天长叹道：" + RANK_D->query_respect(me) + "费心尽力导引我出这迷雾，以后若有差遣，老龙莫敢不从．\n"NOR,me);
}

void longgong_done1()
{
	object me;
	me=this_player();
    command ("sigh");
    message_vision(HIB"\n熬广挥然泪下道：既然是那泾河老弟为堵一时之气，违了玉帝金旨
	也该有如此下场，唉。。。。。。\n\n\n"NOR,me);
}


void dropthing(string thing)
{
  command("drop "+thing);
  return;
}


int begin_yuanshoucheng()
{
	   object me,ob;
    me=this_player();
	ob=this_object();
   if (!me->query("fangcun/panlong_visite"))
	return 0;
		if (me->query_temp("fangcun/panlong_longgong_longzhu")!="done")
			{
		     command ("say 我东海龙王掌管四海水族,有什么心事不能了的？\n");
			 return 1;
	    }

		if ((me->query("fangcun/panlong_longgong")=="done")||(me->query_temp("fangcun/panlong_longgong_yuanshoucheng")=="done"))
	    {
		     command ("say 老龙心事已了，还提陈年旧事作何？\n");
			 return 1;
	    }
	message_vision("\n\n一提到这心事，东海老龙王只恨的咬牙切齿，浑身龙磷怒张！\n\n"NOR,me);
    command("say "+RANK_D->query_respect(me)+"有所不知呀，前日径河水族来报，那泾河龙王被一算命先生陷害昨日午时三
	刻，唐丞相魏征奉玉帝金旨一梦斩之，此仇不报，我水族有何面目再见各路仙家？\n\n");
	command("say 我正为此事发愁，要我兴兵前往必定随风带雨，只恐惊了大唐百姓上天怪罪．"+RANK_D->query_respect(me)+"
	既有如此武功只要打晕了那算命先生给我带来，老龙定然如"+RANK_D->query_respect(me)+"所愿赴灵台观礼．\n");
    me->set_temp("fangcun/panlong_longgong_yuanshoucheng","begin");
return 1;
}

void die()
{
	object me,who,longjin;
    string whoid;
    me=this_object();
    if(me->query_temp("longjin_kill"))
	{
		  whoid=me->query_temp("longjin_kill");
    	  if (!present(whoid,environment()))
        	  return ::die();
	  	  who=present(whoid,environment());
          if((who->query("fangcun/panlong_hell_18")=="done")&&(who->query("fangcun/panlong_hell_longjin")=="begin")&&(environment()))
		{
			  longjin=new("/d/sea/obj/longjin");
			  longjin->move(me);
			  ::die();
			  return; 
		}
	}
      ::die();
}
