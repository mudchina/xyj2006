// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// zhenyuan.c...weiqi, 98.02.24.
// copied a lot of useful functions from "rulai.c"...thanks snowcat:)

#define DEBUG 0
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string expell_me(object me);
string keyword(object me);
string sword_xiaofeng(object me);
string sword_sanqing(object me);
string asked_guo(object me);
string ask_mieyao(object me);
string ask_cancel();
int begin_go();
int give_fu(object ob);

void create()
{
   set_name("镇元大仙", ({"zhenyuan daxian", "zhenyuan", "daxian"}));
   set("title", "五庄观观主");
   set("gender", "男性" );
   set("age", 65);
   set("per", 24);
   set("str", 30);
   set("long", "交游遍三界，桃李漫五行。好一位地仙之祖！\n");
   set("class", "xian");
   set("combat_exp", 5600000);
   set("attitude", "peaceful");
   create_family("五庄观", 1, "祖师");
   set("rank_info/respect", "观主");
   set_skill("unarmed", 180);
   set_skill("wuxing-quan", 200);
   set_skill("dodge", 180);
   set_skill("baguazhen", 160);
   set_skill("parry", 180);
   set_skill("sword", 180);
   set_skill("sanqing-jian", 190);
   set_skill("staff", 160);
   set_skill("fumo-zhang", 190);
   set_skill("hammer", 160);
   set_skill("kaishan-chui", 190);
   set_skill("blade", 160);
   set_skill("yange-blade", 190);
   set_skill("force", 180);   
   set_skill("zhenyuan-force", 180);
   set_skill("literate", 180);
   set_skill("spells", 200);
   set_skill("taiyi", 200);
   map_skill("spells", "taiyi");
   map_skill("force", "zhenyuan-force");
   map_skill("unarmed", "wuxing-quan");
   map_skill("sword", "sanqing-jian");
   map_skill("dodge", "baguazhen");
   map_skill("staff", "fumo-zhang");
   map_skill("blade", "yange-blade");
   map_skill("hammer", "kaishan-chui");

   set("max_kee", 4500);
   set("max_sen", 4500);
   set("force", 5000);
   set("max_force", 2500);
   set("mana", 7000);
   set("max_mana", 3500);   
   set("force_factor", 200);
   set("mana_factor", 200);

   set("spell_qiankun_on", 1); //to use cast qiankun, must set this.
   set("chat_chance_combat", 90);
   set("chat_msg_combat", 
   ({
     (: cast_spell, "zhenhuo" :),
     (: cast_spell, "qiankun" :),
   }) );

   set("inquiry", ([
     "leave": (: expell_me :),
     "灵台观礼": (: begin_go :),
     "离开": (: expell_me :),
     "袖里乾坤": (: keyword :),
     "秘诀": (: keyword :),
     "name": "老夫镇元。\n",
     "here": "这里是五庄观，不过住的可不是道士。\n",
     "三清剑法": (: sword_sanqing :),
     "晓风残月剑法": (: sword_xiaofeng :),
     "晓风残月剑": (: sword_xiaofeng :),
     "三清剑": (: sword_sanqing :),
     "sanqing-jian": (: sword_sanqing :),
     "xiaofeng-sword": (: sword_xiaofeng :),
     "人参果": (: asked_guo :),
    "灭妖": (: ask_mieyao :),
"八卦符":(:give_fu:),
      "cancel": (: ask_cancel :),
   ]) );

   setup();
   carry_object("/d/obj/cloth/xianpao")->wear();
   carry_object("/d/obj/weapon/sword/ruler")->wield();
}

/*
string ask_cancel()
{
    object me=this_player();
if(me->query("secmieyao"))
{
      me->add("daoxing",-2000);
      me->set("m_mieyao",1);
      me->delete("secmieyao_mudage");
      me->delete("secmieyao");
      me->delete("secmieyao/type");
      me->delete("secmieyao/location");
      me->delete("secmieyao/place");
      me->delete("secmieyao/name");
      me->delete("secmieyao/id");
      me->delete_temp("m_mieyao"); 
    return ("没用的东西！");
}
else
{
     return ("不要来烦我！");
}
}

*/

string sword_xiaofeng(object me)  
{
   me=this_player();
/*
   int i;
   i=query("sword_xiaofeng_number");  
   if (i>5)
    {
     message_vision("镇元大仙道：你又来了！\n", me);
     message_vision("镇元大仙道：算了吧，这个你看来是领悟不了的了。。。。。\n", me);
     message_vision("镇元大仙浮手独自看云去了。。。。\n", me);
     return ("看来，你还是回去吧，是命不好吗！\n");
    }
*/
   if((string)me->query("family/family_name")=="五庄观") {
     message_vision("\n镇元大仙低头想了一会儿。。。。。\n", me);
    if(me->query("faith")<1000)
     return ("这个，这个，你还是多多修炼去吧！\n");
     message_vision("镇元大仙低头仔细地想了一会儿。。。。。\n\n", me);
     if( me->query("sword_xiaofeng") == 1 ) 
     return ("刚才不是练给你看了吗？\n");
     message_vision("镇元大仙顺手拿起一把木剑，演练了一下！\n", me);
     if( (int) me->query("combat_exp") < 100000 ) return ("你现在道行太低，只看的云里雾里，一团模糊。\n");
     if( (int) me->query("max_mana") < 2200 ) return ("你现在法力太低，无法领悟。\n");
     if(!me->query_skill("xiaofeng-sword")) return ("你没有这门绝活，怎么也来凑热闹？\n");
     if(me->query_skill("sword",1)<180) 
          return ("你基本剑法还没融会贯通，无法领悟这门外功。\n");
     if( (int)me->query_skill("xiaofeng-sword",1)<180) 
          return ("你晓风残月剑法还没融会贯通，无法领悟这门外功。\n");
     message_vision("镇元大仙道：好！你再看一次...！\n", me);
    if( random( (int) me->query_skill("sword",1)) > 100
         && random( (int) me->query("combat_exp")) > 100000
          && random(me->query("int"))<15 )
        {
          me->set("sword_xiaofeng", 1);
          message_vision("$N会意地笑了，慢慢得深思起来......\n", me);
          command("haha");
          message_vision("镇元大仙点头道：果然是我的弟子！\n", me);
          message_vision("镇元大仙嘱咐道：这次下山当不可坠了我的名声！\n", me);
          return ("好好，你现在可以去了！\n");;
        }
//          me->set("sword_xiaofeng_number", i+1);
          command("hmm");
          command("shrug");
          message_vision("镇元大仙叹气道：虽然是我的弟子，不过.....哎，不过....！\n", me);
          message_vision("镇元大仙似乎想起了什么往事.....\n", me);
          return ("唉，你现在可以去了！\n");
   }
          command("hmm");
          command("heng");
   message_vision("镇元大仙看起来想杀死你!!\n", me);
   return ("想刺探本门秘技，好大的胆子！\n");
}

string sword_sanqing(object me)  
{
   me=this_player();
/*
   int i;
   i=query("sword_sanqing_number");  
   if (i>5)
    {
     message_vision("镇元大仙道：你又来了！\n", me);
     message_vision("镇元大仙道：算了吧，这个你看来是领悟不了的了。。。。。\n", me);
     message_vision("镇元大仙浮手独自看云去了。。。。\n", me);
     return ("看来，你还是回去吧，是命不好吗！\n");
    }
*/
   if((string)me->query("family/family_name")=="五庄观") {
     message_vision("镇元大仙低头想了一会儿。。。。。\n", me);
    if(me->query("faith")<1000)
     return ("这个，这个，你还是多多修炼去吧！\n");
     message_vision("镇元大仙想到细处，不由笑了起来。。。。。\n\n", me);
     if( me->query("sword_sanqing") == 1 ) 
     return ("刚才不是练给你看了吗？\n");
     message_vision("镇元大仙顺手拿起一把木剑，演练了一下！\n", me);
     if( (int) me->query("combat_exp") < 100000 ) return ("你现在道行太低，只看的云里雾里，一团模糊。\n");
     if( (int) me->query("max_mana") < 2200 ) return ("你现在法力太低，无法领悟。\n");
     if(!me->query_skill("sanqing-jian")) return ("你没有这门绝活，怎么也来凑热闹？\n");
     if( me->query_skill("sanqing-jian",1) < 180 ) return ("你这门剑法还没融会贯通，无法领悟这门外功。\n");
     if( me->query_skill("sword",1) < 180 ) return ("你基本剑法还没融会贯通，无法领悟这门外功。\n");
     message_vision("镇元大仙道：好！你再看一次...！\n", me);
    if( random( (int) me->query_skill("sword",1)) > 100
         && random( (int) me->query("combat_exp")) > 100000
          && random(me->query("int"))<15 )
        {
          me->set("sword_sanqing", 1);
          message_vision("$N会意地笑了，慢慢得深思起来......\n", me);
          command("haha");
          message_vision("镇元大仙点头道：果然是我的弟子！\n", me);
          message_vision("镇元大仙嘱咐道：这次下山当不可坠了我的名声！\n", me);
          return ("好好，你现在可以去了！\n");;
        }
          command("hmm");
         message_vision("镇元大仙叹气道：虽然是我的弟子，不过.....哎，不过....！\n", me);
          command("shrug");
          message_vision("镇元大仙似乎想起了什么往事.....\n", me);
          return ("唉，你现在可以去了！\n");
   }
          command("heng");
          command("hmm");
   message_vision("镇元大仙看起来想杀死你!!\n", me);
   return ("想刺探本门秘技，好大的胆子！\n");
}

string ask_mieyao(object me)
{
    me=this_player();
     if((string)me->query("family/family_name")=="五庄观") {
//  if(me->query("faith")<100)
//      return ("你还是先多加修炼为妙。");
    tell_room(environment(me),"镇元大仙念念有词.....\n");
    return "/d/obj/mieyao"->query_yao(me);
}
     return ("贫道不知。");
}
void attempt_apprentice(object ob)
{
   if( (string)ob->query("class")=="dao" )
     command("say 好，好！道仙本一家。\n");
   
  //}

   if( (string)ob->query("family/family_name")=="五庄观" )
   {
     if( (int)ob->query("family/generation") > 3   )
     {
        command("say 福禄寿他们正想多收几个弟子，你先到那边看看吧。\n");
     }
     else 
     {
        if( (int)ob->query("combat_exp") >= 300000 && (int)ob->query_skill("taiyi", 1) >= 120 )
        {
          command("nod ");
          command("say 好，" + RANK_D->query_respect(ob) + "不愧是本门的人才！\n");
          command("recruit " + ob->query("id") );
        }
        else
        {
          command("say 有心上进是不错，不过还是要循序渐进。\n");
        }
     }
   }

   else
   {
     command("nod");
     command("say 这位" + RANK_D->query_respect(ob) + "，本门讲究长幼之礼，尊卑之分。一下让你成为二代弟子恐人心不服。\n");
   }

   return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "xian");
}

string expell_me(object me)
{       
   me=this_player();
   if((string)me->query("family/family_name")=="五庄观") {
     message_vision("镇元大仙道：你既然要走，那也不能强留。但是太乙仙法是五庄观不传之秘，可不能带出观外。\n", me);
     me->set_temp("asked_leave_wzg", 1);
     return ("你可真是要走(true)？\n");
   }
   return ("清风，明月，送客！\n");
}

string keyword(object me)
{       
   me=this_player();
   if((string)me->query("family/family_name")=="五庄观") {
     message_vision("镇元大仙道：你是指袖里乾坤的六字真诀吧。\n", me);
     if( me->query("spell_qiankun_on") == 1 ) return ("不是已经告诉你了吗？\n");
     if( (int) me->query("combat_exp") < 10000 ) return ("你现在道行太低，施用袖里乾坤恐危及性命。\n");
     if( (int) me->query("max_mana") < 300 ) return ("你现在法力太低，施用袖里乾坤恐危及性命。\n");
     message_vision("镇元大仙道：好！你听着...言罢伸掌在$N头顶一拍！\n", me);
     me->set("spell_qiankun_on", 1);
     return ("六字真诀已经告诉你了，去罢！\n");
   }
   command("kick");
   return ("想刺探本门秘技，好大的胆子！\n");
}


void init()
{
        
     object ob = this_player();
        if( ob->query_temp("kill_tree") )
        {
        command("say 小杂毛，如果不把我的人参果树救活，别怪老夫不客气了。");
        command("slap "+ob->query("id"));
        }
		if((ob->query_temp("get_guo")<=3 )&&(ob->query("fangcun/panlong_wzg_rsg")!="done")&&(ob->query("fangcun/panlong_wzg_baxian")=="done"))
	    {
     	     message_vision("镇元大仙对$N道：不是叫你拿三个果的吗？！\n\n",ob);
		}
		if( ob->query_temp("get_guo")>=4 )
        {
			call_out("finish_wzg",2,ob);
		}
   add_action("do_true", "true");
   add_action("do_back", "back");
}

void finish_wzg(object me)
{
	if((!present("jinji zi",me))||(!present("dan pan",me)))
       {
   	     message_vision("镇元大仙对$N道：" + RANK_D->query_respect(me) + "我的金击子和丹盘呢？\n\n",me);
         return;
        }	
	command("pat "+me->query("id"));
    message_vision("\n\n镇元大仙笑眯眯的对$N说道：" + RANK_D->query_respect(me) + "来我五庄观这些日子没有什么好招待，这人
	参果乃我五庄观宝物一颗敬献尊师菩提道兄算老夫他日灵台观礼的贺礼．
	一颗还烦劳" + RANK_D->query_respect(me) + "送到灵山代我敬献如来佛祖．一颗当然给小兄弟自己
	了．不过" + RANK_D->query_respect(me) + "可要切记，送这人参果给如来佛祖之时，需从我"+HIW"乘云阁
	"+NOR"出发，一路"+HIY"步行"+NOR"十万八千里直到"+HIW"大雄宝殿"+NOR"方才显出" + RANK_D->query_respect(me) + "之诚心．\n\n", me);
	if( me->query_temp("get_guo")>=5 )
         me->set("fangcun/panlong_nowaywzg1",1);
	 me->set("fangcun/panlong_nowaywzg2",1);
	 me->set("fangcun/panlong_nowaywzg3",1);
	 destruct(present("jinji zi",me));
     destruct(present("dan pan",me));
	  
	     me->set("fangcun/panlong_wzg_rsg","done");
		 me->delete_temp("get_guo");
	call_out("cut_jinpan",1,me);
}

void cut_jinpan(object me)
{
     message_vision(HIY"\n\n镇元大仙哈哈大笑，袍袖一挥．顿时将$N身上的金击子和丹盘收了回去！\n\n"NOR,me);
}

int do_true(string arg)
{
   if(this_player()->query_temp("asked_leave_wzg")) {
     message_vision("$N答道：弟子真的想走！\n\n", this_player());
     message_vision("镇元大仙叹了口气道：好！回来还是客。\n", this_player());
     this_player()->add("betray/wuzhuangguan", 1);
     this_player()->add("betray/count", 1);
     this_player()->set("combat_exp", this_player()->query("combat_exp")/100*80);
     this_player()->set("daoxing", this_player()->query("daoxing")/100*80);
     this_player()->delete_skill("taiyi");
     this_player()->delete("family");
     this_player()->set("faith",0);
     this_player()->delete("class");
     this_player()->set("title", "普通百姓");
     this_player()->delete_temp("asked_leave_wzg");
     this_player()->delete("spell_qiankun_on");
     this_player()->save();
     message_vision("说罢在$N头上一按，$N只觉浑身一轻，空荡荡地好像丢了什么。\n", this_player());
     return 1;
   }
   return 0;
}

//the following is for renshen dahui...

void announce (object me, string str)
{
   if (DEBUG)
   { 
     object weiqi = find_player ("weiqi");
     if (weiqi && wizardp(weiqi))
        tell_object (weiqi,"◆ "+str+"\n");
   }
   else
   {
     CHANNEL_D->do_channel(me,"chat",str);
   }
}

void start_renshen()
{
   object me;

   me = this_object();
    
   set_temp("invite","public");

   announce (me, "五庄观人参果品尝大会即将开始！\n");
   set_temp("give_num",0);
   call_out("ready1", 10);
   set_temp("ready0", 1);
}

void ready1()
{
   object me;

   me = this_object();

   announce (me, "五庄观人参果品尝大会马上就要开始！\n");
   call_out("ready2", 5);
   set_temp("ready1", 1);
}

void ready2()
{
   object me;

   me = this_object();

   announce (me, "五庄观人参果品尝大会现在开始！\n");
   set_temp("ready2", 1);
}

string asked_guo(object me)
{ 
	int i, total;
	object guo;
	object *inv ;
      
	me=this_player();

	//if no renshenguo party at all...
	if( query_temp("ready0") != 1 ) return ("人参果可是个好东西。\n");

	//if not in the right place, no guo...
	//need the right name, also right outdoors(so ppls can not use fake room).
	if( (environment(this_object()))->query("short") != "人参果园" || 
		(environment(this_object()))->query("outdoors") != "wuzhuang" )
	{
		return ("这里又不是果园，哪来的人参果。\n");
	}
        if( userp(me) && (!wizardp(me))  )
           { 
           	if(query_temp("give_num")<3&&me->query_temp("give_rsg")!=1)
           	  {
           	    me->set_temp("give_rsg",1);
                    add_temp("give_num",1);
                  }  
           }  
	
	//if waiting for ppls...
	if( query_temp("ready1") != 1 ) return ("不要急，再等等。\n");
        
         //if ready to begin...
        if( query_temp("ready2") != 1 ) return ("不要急，马上就有。\n");

        if( query_temp("give_num") < 3 ) return ("不要急，再等等。\n");
	
	//if finished...
	if( query_temp("finished") == 1 ) return ("人参果已分发完了。\n");

	//now check how many people here...
	total = 0;
	inv = all_inventory( environment(this_object()) );
	for(i=0; i<sizeof(inv); i++)
	{
		if( inv[i]->query_temp("give_rsg")==1 )
	  	 {
	  	   guo = new("/d/obj/drug/renshen-guo");
		   guo->move(inv[i]);
	  	   message_vision("$N给$n一枚人参果。\n", this_object(), inv[i]);
		   announce (this_object(), "恭喜恭喜！" + inv[i]->query("name") + "获得人参果一枚。\n");
		   inv[i]->delete_temp("give_rsg");
		 }
	}	 
		
		set_temp("finished", 1);
		call_out("finishing", 10);

		return ("好！人参果分发完毕，诸位仙贤尽情享用吧。\n");
	
	
}


void finishing()
{
   message_vision("$N哈哈大笑几声，顿时无影无踪了。\n", this_object());
   delete_temp("invite");//this is necessary if not going to destruct this obj.
   destruct(this_object());
}

void inviting (object me)
{
   int i;
   object *list;

   if (! me->query_temp("invite"))
   return;
  
   remove_call_out ("inviting");
   call_out ("inviting",4+random(4),me);

   list = users();
   i = sizeof(list);
   while  (i--)
   {
     string here, there;

     reset_eval_cost();
    
     if (!environment(list[i]))
        continue;
    
     if (environment(list[i])->query("unit")) // not a room
        continue;
   
     if (list[i]->is_fighting())
        continue;
    
     if (list[i]->is_busy())
        continue;
    
     if (list[i]->query_temp("no_move"))
        continue;
    
     if (!living(list[i]))
        continue;
    
     if ((string)list[i]->query_temp("accept")!=me->query("id"))
        continue;

     list[i]->set_temp("accept",0);
     here = (string)environment(me);
     there = (string)environment(list[i]);
     if (here == there)
        continue;

     message_vision("$N的大袖往外一罩…\n",me);
     list[i]->set_temp("accept",0);
     list[i]->set_temp("wzg/from",there);

     message_vision("一团祥云飘来，云中伸出一只巨大的衣袖将$N轻轻一罩，消失在天空。\n",list[i]);
         list[i]->move(here);
     message_vision("…$N大袖轻轻一抖，$n滑了出来。\n",me,list[i]);
     break;
   }
}

int do_back(string arg)
{
   object who = this_player();
   object me = this_object();
   string here = (string)environment(me);
   string there = who->query_temp("wzg/from");

   message_vision("$N请求$n送$N回返。\n",who,me);
 
    //if (!there)
   // there = "/d/city/kezhan";
   there = "/d/city/kezhan";

   who->set_temp("accept",0);
   message_vision("$N的大袖朝着$n轻轻一罩…\n",me,who);
   who->move(there);
   message_vision("…云中伸出一只巨大的衣袖轻轻一抖，只见$N从里面滑了出来。\n",who);
  
   return 1;
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

int give_fu(object ob)
{
        object who, me;
        who=this_player();
        me=this_object();
        if( (string)who->query("family/family_name")!="五庄观" ) {
                message_vision("$N斜斜地瞟了$n一眼，说：此不足为外人道也！\n", me, who);
                return 1;
        }
if ((int)who->query("combat_exp") < 300000||who->query_skill("taiyi",1)<61)
                 {  message_vision("$N斜斜地瞟了$n一眼，说：你会不会用奇门八卦？\n", me, who);
                       return 1;}
       if ((int)who->query("faith") < 500) {
           message_vision("$N恶狠狠地看了$n一眼，说：你为本派出过多少力？\n", me, who);
                       return 1;}
	if ((int)me->query("number") >= 1)
          { write("镇元大仙把手一伸，今天给太多了，明儿个再说吧！\n");
          return 1;
}
                ob=new("/d/obj/misc/baguafu.c");
                ob->move(who);
		me->add("number",1);
		message_vision("$N拿出张符纸来，歪歪扭扭画了几个字，塞给了$n。\n", me, who);
                return 1;
}


int begin_go()
{
	object me,ob,jin,pan;
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
    if (me->query("guanli/wzg"))
	  return 0;
    
		if (me->query("fangcun/panlong_wzg")=="done")
	{
        message_vision(HIW"\n镇元大仙道：既然"+RANK_D->query_respect(me)+ "来请,老夫这就动身！\n"NOR,me);
        message_vision(HIY"\n\n镇元大仙已然驾祥云往三星洞飞去！\n"NOR,me);
		ob->move("/d/lingtai/inside1");
        return 1;
	}
	    if ((me->query("fangcun/panlong_wzg_baxian")=="done")&&(me->query("fangcun/panlong_wzg_rsg")=="done"))
	{
		me->add("fangcun/panlong_visite",1);
		me->set("fangcun/panlong_wzg","done");
		me->delete("fangcun/panlong_wzg_baxian");
		me->delete("fangcun/panlong_wzg_rsg");
       message("chat",HIC+"〖"+HIW+"西游记2006"+HIC+"〗镇元大仙(Zhenyuan daxian)："+me->query("name")+RANK_D->query_respect(me)+"了我八个徒孙心愿，他日灵台观礼老夫定来捧场！\n"NOR,users());
         message("chat",HIC+"〖"+HIW+"西游记2006"+HIC+"〗镇元大仙(Zhenyuan daxian)："+me->query("name")+"得到奖励：道行"+chinese_number(dx1)+"年，武学"+wx+"点，潜能30000点．\n"NOR,users());
   	    if (me->query("family/family_name")=="方寸山三星洞")
		   message_vision("\n镇元大仙笑道：观礼之日还望" + RANK_D->query_respect(me) + "再来通知老夫一声.\n"NOR,me);
		me->add("daoxing",dx);
		me->add("combat_exp",wx);
		me->add("potential",30000);
	    if ((me->query("family/family_name")!="方寸山三星洞")||(me->query("fangcun/panlong_noway")))
			me->set("guanli/wzg",1);
		return 1;
	}
	if ((me->query("fangcun/panlong_wzg_baxian")=="done")&&(me->query_temp("get_guo")))
	{
              command("hmm "+me->query("id"));
    		  command("say 难道" + RANK_D->query_respect(me) + "不去拿人参果了吗？\n");
			  return 1;
	}
	if (me->query("fangcun/panlong_wzg_baxian")=="done")
	{
	          command("haha "+me->query("id"));
    		  command("say " + RANK_D->query_respect(me) + "帮我了了徒孙的心愿，这里有些东西送给你和尊师菩提，" + RANK_D->query_respect(me) + "先去我那人参果树上打"+HIY"三个"+NOR""+CYN"果子来．\n");
   	  	      message_vision("\n镇元大仙笑着给$N一把金击子和一个丹盘．\n"NOR,me);
			  jin=new("/d/qujing/wuzhuang/obj/jinjizi");
			  jin->move(me);
			  pan=new("/d/qujing/wuzhuang/obj/danpan");
			  pan->move(me);
			  me->set_temp("get_guo",1);
			  return 1;
	}


    if (me->query("fangcun/panlong_wzg")!="begin")
    {
  command("say " + RANK_D->query_respect(me) + "来的正好，我那八个徒孙近日来不知怎么，心事重重．我平日里管教
              又严几个小家伙都不敢说实话，" + RANK_D->query_respect(me) + "正好帮老夫去打听打听他们有什么烦恼．\n");
   me->set("fangcun/panlong_wzg","begin");
        if ((me->query("family/family_name")!="方寸山三星洞")||(me->query("fangcun/panlong_noway")))
        	me->set_temp("wzg_baxian","go");
	return 1;
	}
  command("say 如何，" + RANK_D->query_respect(me) + "打听到了什么？\n\n");
  if ((me->query("family/family_name")!="方寸山三星洞")||(me->query("fangcun/panlong_noway")))
        	me->set_temp("wzg_baxian","go");
  return 1;
}
