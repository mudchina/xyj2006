
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// yushu.c, 玉鼠精
// created by mes, updated 6-20-97 pickle
// updated again by pickle on 9-2-97, to open her menpai

/************************************************************/

// declarations and variables

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
   string ask_mieyao();
   string ask_cancel();
string say_key();
void punish_player(object me);
   string ask_swear();
int accept_object(object me, object ob);

/************************************************************/
void create()
{
  set_name("玉鼠精", ({"yu shu","yushu", "shu", "monster"}));
    set_weight(1000000);
  set("gender", "女性" );
  set("age", 23);
  set("long", 
"她就是这无底洞的洞主了。她从修道成人行以来，吃人无数，\n"
"也不知为什么玉皇还未曾派兵来围剿。听说她在天宫有亲，也\n"
"不知真假。\n");
  set("title", "地涌夫人");
  set("combat_exp", 1500000);
  set("attitude", "heroic");
  set("daoxing", 3000000);
  create_family("陷空山无底洞", 1, "弟子");
  set("int", 25+random(5));
  set("cor", 30+random(10));
  set_skill("unarmed", 150);
  set_skill("dodge", 180);
  set_skill("parry", 160);
  set_skill("spells", 160); 
  set_skill("yaofa", 160);
  set_skill("sword",190);
  set_skill("qixiu-jian",190);
  set_skill("blade", 180);
  set_skill("kugu-blade", 200);
  set_skill("lingfu-steps", 150);
  set_skill("yinfeng-zhua", 150);
  set_skill("force", 180);   
  set_skill("huntian-qigong", 180);
  map_skill("force", "huntian-qigong");
  map_skill("spells", "yaofa");
  map_skill("unarmed", "yinfeng-zhua");
  map_skill("sword", "qixiu-jian");
  map_skill("parry", "kugu-blade");
  map_skill("blade", "kugu-blade");
  map_skill("dodge", "lingfu-steps");
  set("per", 50);
  set("max_kee", 2500);
  set("max_sen", 2500);
  set("force", 3800);
  set("max_force", 2000);
  set("force_factor", 150);
  set("mana",3000);
  set("max_mana", 3000);
  set("mana_factor", 50);
  set("inquiry",([
// "斗佛" : (: ask_mieyao :),
    "cancel" : (: ask_cancel :),
       "key": (: say_key :),
       "钥匙": (: say_key :),
       "name": "老娘就是这无底洞的开山祖师！",
    "发誓" : (: ask_swear :),
       "here": "这里就是陷空山无底洞！就算你调十万天兵来也奈何我不得！",
       "rumors": "老娘刚刚抓住一个和尚。看来马上就有新鲜人肉吃了。",
       "人肉包子": "混帐！饿了不会去找厨子？",
       "和尚": "嘿嘿，眼下正饿着他呢。等他肠子干净了就可以蒸熟了吃了。\n"
          "不过也该派人去看看他了。说不定他已经饿死了。",
       "看看": "要看看也行，就是不知道我把钥匙放哪儿了。",
       ]));
  set("chat_chance_combat", 60);
   
   set("chat_msg_combat", ({
     (: exert_function, "zhangqi" :),
        (: perform_action,"blade", "pozhan" :),
        (: perform_action,"blade", "diyu" :),
   }) );
  setup();
  carry_object("/d/obj/weapon/blade/yanblade")->wield();
  carry_object("/d/obj/cloth/nichang")->wear();
  carry_object("/d/obj/cloth/yuanxiang")->wear();
}
/**************************************************************/
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

    if(me->query("family/family_name")!="陷空山无底洞")
      return ("你不是本门中人!");

   command("pat "+me->query("id"));
    command("say 有志气！");
   return "/d/obj/mieyao"->query_yao(me);
}

int attempt_apprentice(object me)
{
  string myname=RANK_D->query_rude(me);
  string myid=me->query("id");
  command("look "+myid);
  command("consider");
  if(me->query("family/master_id") != "tian shu" && me->query("combat_exp") < 200000)
  {
      command("say 什么东西？给我滚！");
      return 1;
  }
  if (me->query("wudidong/sell_reward") < me->query("combat_exp") / 20)
  {
    command("say "+myname+"要想入我门下，先多去弄些人肉来，老娘看你心诚，这拜师就好商量了。");
    return 1;
  }
  if (me->query_skill("huntian-qigong", 1) < 50 && me->query("combat_exp") < 200000)
  {
    command("say "+me->name()+"你个废物！就凭那点本事还不配！");
    return 1;
  }
  command("grin");
  command("say 老娘最爱吃人肉包子了。"+myname+"别忘了多给厨房弄点原料！");
  command("recruit "+myid);
  return 1;
}
int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob))
  {
    ob->set("class", "yaomo");
  ob->set("title", YEL"陷空山地涌夫人座下弟子"NOR);
  }
}
/************************************************************/

// the prevent learn series... first yushu tosses the player
// if he's saved the monk, and second she has condition of
// learning kugu-blade.

int prevent_learn(object me, string skill)
{
  int mykugu=me->query_skill("kugu-blade", 1);
  if (wizardp(me) && me->query("env/immortal"))
    return 0;
  if (skill == "kugu-blade")
  {
      if (mykugu>=200)
      {
   command("say 你又用不着我来教！难道是来消遣老娘的？");
   return 1;
      }
      if (mykugu<200 && me->query("wudidong/given_book_3")) return 0;
      if (mykugu<141 && me->query("wudidong/given_book_2")) return 0;
      if (mykugu<=81 && me->query("wudidong/given_book_1")) return 0;
      command("say 不教！此乃无底洞不传之密！");
      return 1;

    }
  if (skill == "yaofa" && me->query("obstacle/wudidong")=="done")
  {
      call_out("punish_player", 1, me);
      return 1;
  }
  return 0;
}
int accept_object(object me, object ob)
{
    int volume;
    if(ob->query("name_recognized") != "枯骨刀秘笈")
        return notify_fail(CYN"玉鼠怒道：混帐，我又不是收破烂的！\n"NOR);
    volume=ob->query("册");
    me->set("wudidong/given_book_"+(string)volume, 1);
    if (me->query("family/master_id") != "yu shu")
   command("say 嗯，果然不错。老娘自当履行诺言，收你为徒！");
    command("recruit "+me->query("id"));
    if (me->query("family/master_id") == "yu shu")
   command("say 好徒弟，果然不枉了师父的一番调教。");
    return 1;
}

void punish_player(object me)
{
    object *inv, ob;
    int i;
    inv=all_inventory(me);
    i=(int)sizeof(inv);
    while(i--)
    {
        ob=present(inv[i],me);
        destruct(ob);
        continue;
    }
    command("say "+me->name()+"你个混帐！叫你去好好看着那老秃驴，你竟敢把他给放跑了！");
    command("say 你好大的胆子！还敢回来跟老娘学本事！");
    command("say 不好好教训教训你，别人还都以为老娘是好欺负的了！");
    message_vision("只见玉鼠左手掐了个决，口中念念有词，对$N喝道：倒！\n", me);
    me->unconcious();
    message_vision("玉鼠精象提小鸡般提起$N，往后一扔。$N不见了！\n", me);
    me->move("/d/qujing/wudidong/punish");
    message("vision", "只听“咚”的一声，$N落了下来！\n", me);
    return;
}
/*********************************************************************/
string say_key()
{
  object me=this_player(), ob, npc=this_object();
  int mykar=me->query_kar();
  int real_key_condition;

  if(npc->is_fighting() || me->is_fighting())
    return ("没门！等着点！");
  if (member_array("tian shu",me->parse_command_id_list())==-1 )
    {
      call_out("killplayer", 1, me);
      return ("哪儿来的"+RANK_D->query_rude(me)+"？找死！");
    }
  message_vision(CYN"玉鼠对$N说：“好吧，拿去。”\n"NOR, me);
  if (npc->query_temp("gave_out_key"))
      real_key_condition=0;
  else real_key_condition=1;
  if (!real_key_condition)
    {
      ob=new("/d/qujing/wudidong/obj/key-fake");
    }
  else if (random(mykar)>8)
    {
      ob=new("/d/qujing/wudidong/obj/key-real");
      npc->set_temp("gave_out_key", 1);
    }
  else ob=new("/d/qujing/wudidong/obj/key-fake");
  ob->move(me);
  me->set_temp("mark/wudidong_yushu_gave_me_key", 1);
  return ("好好看守那秃驴！\n");
}
void killplayer(object me)
{
  this_object()->kill_ob(me);
}
/**************************************************************/
void init()
{
//       add_action("do_swear", "swear");
  object me;

  ::init();
  if( interactive(me = this_player()) && !is_fighting() ) {
    call_out("greeting", 1, me);
  }
}
void greeting(object me)
{
  int myspells=me->query_skill("spells");
  int mykar=me->query_kar();
  string npcname=this_object()->query("name");
  string npcrude=RANK_D->query_self_rude(this_object());
  string myrude=RANK_D->query_rude(me);

  if( !me || environment(me) != environment() ) return;
  if( me->query("family/family_name") == "陷空山无底洞")
    return;
  if( member_array("yu shu", me->parse_command_id_list())!=-1)
    {
      command("say 哪个混账？竟敢变成"+npcrude+"样子招摇撞骗？！找死！");
      kill_ob(me);
      return;
    }
  if( member_array("tian shu",me->parse_command_id_list())==-1 )
    {
      command("say 哪里来的"+myrude+"？无底洞不是你撒野的地方！拿命来！");
      command("kill " + me->query("id"));
      return;
    }
  if( random(mykar) > 8) return;
  else
    {
      message_vision(CYN ""+npcname+"对$N大喝道：呔！什么东西！？休想从"+RANK_D->query_self_rude(this_object())+"眼下溜过去！\n"NOR, me);
      message_vision(npcname+"大喊一声：现！$N顿时现出原形，原来是"+me->query("name")+"！\n", me);
      me->delete_temp("spellslevel");
      me->delete_temp("d_mana");
      me->delete_temp("apply/name");
      me->delete_temp("apply/id");
      me->delete_temp("apply/short");
      me->delete_temp("apply/long"); 
      kill_ob(me);
      return;
    }
}



//int do_swear()
string ask_swear()
{
	object me;
	int amount,i;
	mapping skills;
	string *skillsname;
	me=this_player();
        me->command("say 我愿意效忠夫人，永远做无底洞的好弟子。");
	if (mapp(skills = me->query_skills()))
            {
               skills = me->query_skills();
               skillsname = keys(skills);
               amount = sizeof(skills);
               for (i = 0; i < amount; i++)
                {if (skillsname[i]!="qixiu-jian"
                     && skillsname[i]!="kugu-blade"
                     && skillsname[i]!="yinfeng-zhua"
                     && skillsname[i]!="daya-jian"
                     && skillsname[i]!="yaofa"
                     && skillsname[i]!="huntian-qigong"
                     && skillsname[i]!="blade"
                     && skillsname[i]!="dodge"
                    && skillsname[i]!="lingfu-steps"
                     && skillsname[i]!="stealing"
                     && skillsname[i]!="sword"
                     && skillsname[i]!="parry"
                     && skillsname[i]!="unarmed"
                     && skillsname[i]!="literate"
                     && skillsname[i]!="force"
                     && skillsname[i]!="spells")
                    {command("say 你身怀其他门派的武功，叫我如何信你？"); 
//return 1;}  
return ("你不是本门中人!");
}
                  }
                     command("say 好，希望你能担负起发扬无底洞的重任，为我派争光。");
                     me->delete("betray/count", 1);
                     me->delete("betray/wudidong", 1);
                     me->delete("betrayer", 1);
                     me->set("maximum_force",me->query("max_force"));
            }        
return ("好好努力!");
}    
