// huangfengguai.c, 黄风怪
// created by smile and wxb 12/14/1998

#include <ansi.h>
inherit NPC;

string say_zhu();
int query_hupi(object me);

void create()
{
  set_name("黄风怪", ({"huangfeng guai","guai","huangfeng","huang"}));
  set("long","红眉褐发，威风凛凛。人称黄风大王。\n");
    set("gender", "男性" );
  set("age", 40);
  set("title", "黄风岭大王");
  set("combat_exp", 900000);
  set("attitude", "friendly");
  set("int", 30);
  set("cor", 35);
  set_skill("unarmed", 150);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set_skill("spells", 150); 
  set_skill("yaofa", 150);
  set_skill("fork", 150);
  set_skill("fengbo-cha", 150);
  set_skill("lingfu-steps", 100);
  set_skill("yinfeng-zhua", 120);
  set_skill("force", 150);   
  set_skill("huntian-qigong", 160);
  map_skill("force", "huntian-qigong");
  map_skill("spells", "yaofa");
  map_skill("unarmed", "yinfeng-zhua");
  map_skill("parry", "kuangfeng-cha");
  map_skill("fork", "kuangfeng-cha");
  map_skill("dodge", "lingfu-steps");
  set("per", 10);
  set("max_kee", 1200);
  set("max_sen", 1200);
  set("force", 1200);
  set("max_force", 1200);
  set("force_factor", 100);
  set("mana", 1400);
  set("max_mana", 1400);
  set("mana_factor", 100);
  set("inquiry",([
		  "珠": (: say_zhu :),
		  "定风珠": (: say_zhu :),
                "zhu":(: say_zhu :),
		  "name": "老子就是这黄风岭的大寨主！",
		  "here": "这里就是黄风岭！",
		  ]));
  setup();
  carry_object("/d/qujing/huangfeng/obj/cha")->wield();
  carry_object("/d/qujing/huangfeng/obj/jinyipifeng")->wear();
  carry_object("/d/qujing/huangfeng/obj/toukui")->wear();
}

string say_zhu()
{
  object  me=this_player();
  object  ob;
  object  npc=this_object();

  if(npc->is_fighting() || me->is_fighting())
    return ("哼，老子先剁了你再说！");

  if (((me->parse_command_id_list())[0]!="hu xianfeng")||query_hupi(me)!=0)
    {
      call_out("killplayer", 1, me);
      return ("哪儿来的"+RANK_D->query_rude(me)+"？胆敢窥探本大王的宝贝,看招！");
    }
  message_vision(CYN"黄风怪对$N说：“不知宝贝有没有丢失，你去看看。”\n"NOR, me);
  message_vision(CYN"黄风怪对$N叮咛道：“要小心看住，不要有所闪失！”\n"NOR,me);
  if (!me->query_temp("mark/huangfeng_guai_gave_me_key"))
   {
      ob=new("/d/qujing/huangfeng/obj/key");
      npc->set_temp("gave_key", 1);
      ob->move(me);
      me->set_temp("mark/huangfeng_guai_gave_me_key", 1);
      message_vision(YEL"黄风怪给$N一把钥匙。\n"NOR,me);
   }
   return ("看好那宝贝！好好干，本王不会亏待你的。\n");
}

void killplayer(object me)
{
  this_object()->kill_ob(me);
}

int query_hupi(object me)
{
   object *inv;
   int i,num;
   int hupi_flag_find=0;
   inv = all_inventory(me);
   num=sizeof(inv);
   if(num<=0) return -1;
   i=0;
   while(i<num)
    {
     if((inv[i]->short()=="虎皮(Hu pi)")&&(inv[i]->query("equipped")!=0))
        hupi_flag_find=1;
        i=i+1;
    } 
    if(hupi_flag_find==1) return 0;
    else return 1;
}

void init()
{
  object me;

  ::init();
  if( interactive(me = this_player()) && !is_fighting() ) {
    call_out("greeting", 1, me);
  }
}

void greeting(object me)
{
  if(!me || environment(me) != environment() ) return;

 if(me->query_temp("obstacle/has_here")!=0) return;
   me->set_temp("obstacle/has_here",1);
  if(((me->parse_command_id_list())[0]!="hu xianfeng")||query_hupi(me)!=0)
    {
      command("say 哪来的混账？竟敢混入黄风洞？！看招！");
      kill_ob(me);
      return;
    }
}

int test_player (object who)
{
  object  me=this_player(),zhu;
  if( !(zhu = present("dingfeng zhu", me)) ) 
    return 0;
   return 1;    
}

void destruct_me (object me)
{
  destruct (me);
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  message_vision("\n$N趴在地上大口的喘着气。\n",me);
  ob->set_temp("obstacle/huangfeng_huangfengguai_killed",1);
 if(ob->query_temp("obstacle/huangfeng_zhu_getted")!=0)
  {
  message_vision ("\n半空中飞出一条八爪金龙，一把抓住$N，提着头，摔在山石崖边。\n",me);
  message_vision ("$N趴在地上，现了本相，却是一个黄毛貂鼠。又被那龙一把抓起，腾空而去。\n",me);
  }
 else
  {
      command("drop bonnet");
      command("drop pifeng");
      command("drop dao");
    message_vision("\n你眨一眨眼,$N往沙里一钻，没了。\n",me);
   }

  call_out ("lingjipusa_appearing",1,ob);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",2,me);
}

void lingjipusa_appearing (object who)
{
  object  me=this_player();
  object lingjipusa = new ("/d/qujing/huangfeng/npc/lingjipusa");
  object where = environment(me);
  lingjipusa->move(where);
  lingjipusa->call_out_announce_success (who);
}

void unconcious ()
{
  die ();
}

int accept_fight(object ob)
{
  ob->apply_condition("killer", 100);
  kill_ob(ob);
  return 1;
}

void kill_ob (object ob)
{
  object me = this_object();

  set_temp("my_killer",ob);
  call_out ("hurting",random(5)+5,me,ob);  
  ::kill_ob(ob);
}

void hurting (object me, object ob)
{
  string msg ="$N回过头来，将口张了三张，呼的一口气吹将出去,忽然间一阵黄风从空刮起！\n";
  string *strs = ({"( $N大叫一声,被狂风刮到半空中,又重重的跌在山石上！ )\n",
    "( $N大叫一声,被风沙埋了半身！ )\n",
    "( $N狂叫一声，被风沙活埋了！ )\n",
  });
  int damage;

  if (! me)
    return;

  if (! ob)
    return;

  if (environment(ob) != environment(me))
    return;
 
  message_vision (HIG+"\n"+msg+NOR,me,ob);
  
  if (! test_player(ob))
  {
    message_vision (HIY+strs[random(sizeof(strs))]+NOR,ob);
    damage = ob->query("max_kee")/(6+random(3));
    ob->add("kee",-damage); 
    ob->add("eff_kee",-damage); 
    ob->add("sen",-damage); 
    ob->add("eff_sen",-damage); 
  }
  else
  {
    message_vision (HIW+"只见$N身上的定风珠发出一道金光，风沙立刻平息了。\n"+
                    "$n顿时慌了神，转过身就想溜！\n"+NOR,ob,me);
    command("cast huanying");
   }
  remove_call_out ("hurting");  
  call_out ("hurting",random(10)+10,me,ob);  
}


