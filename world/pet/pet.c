// By Canoe 2001-06-11
// 增加宠物存档命令
// 减少宠物answer命令
// 增加宠爱\鞭打\陪练\喂养 命令
//     dote\flog\peilian\feed
//    sloth\cool\tonicity\zhongcheng
//    懒惰 、冷静、强壮、忠诚  
// block函数是个公有函数,

#include <ansi.h>
inherit NPC;
inherit F_SAVE;

private string SAVE_NAME="pet_save";
private static int can_save=1;


void create()
{       
      seteuid(getuid());
        set_name("宠物", ({"pet"}) );
           set("gender", "女性");
        set("race","野兽");
        set("age", 1);
        set("base_name","兔");
        set("attitude", "friendly");
        set("long","小家伙。相关命令：peilian dote feed flog\n");
        set("combat_exp", 100);
        set("daoxing",100);
        set("str",3);//力量
        set("str",3);
        set("cor",3);
        set("per",3);//容貌
        set("spi",3);//灵性
        if(query("sloth"))
        set("cps",3+(int)query("sloth")/100);//冷静
        else set("cps",3);
        if((int)query("cool")>(int)query("sloth"))
        set("con",3+((int)query("cool")-(int)query("sloth"))/100);//体质
        else set("con",3);
        if(!query("zhongcheng")) set("zhongcheng",100);// 忠诚
        set("owner","canoe");
        set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
          set("verbs", ({ "bite", "claw" }) );
        set("ride/msg", "骑");
        set("ride/dodge", 20);
        set_temp("apply/attack", 60);
        set_temp("apply/armor", 60);
        set("is_pet",1);
        setup();
}

void reset()
{
        if( !environment() || ! find_living(query("owner")) )
        {
                destruct(this_object());
                return;
        }
}
void unconcious()
{
        return die();
}
string query_save_file()
{
        string id;
        id = query("owner");
        if( !id ) return 0;
        return sprintf(DATA_DIR"pet/%c/%s", id[0], id);
}
int save()
{
        string file;
        if( stringp(file = this_object()->query_save_file()) ) {
                assure_file(file+ __SAVE_EXTENSION__);
                return save_object(file);
        }
        return 0;
}
int block(object me,object pet)
{     
      if(pet->query("owner")!=me->query("id")) 
          {
           write("宠物不认识你,怕被你拐卖,撅着嘴不敢理你。\n"); 
           return 0;
          } 
      if(me->is_busy()|| me->query_temp("pending/exercising")||me->is_fight()) 
           {
           write("你正忙着呢。\n");
           return 0;
           }  
      if(environment(me)->query("no_fight")  ||
      	 environment(me)->query("no_magic") )
      	   {
      	   write("安全区禁止逗弄宠物。\n");
      	   return 0;
      	   }
      else return 1;  
}
int restore()
{
        string file;

        if( stringp(file = this_object()->query_save_file()) )
                return restore_object(file);
        return 0;
}
void die()
{       
        int i;
        object owner, *enemy;
        int gin,kee,sen,exp;
        
        exp = (int) query("combat_exp");
        gin = (int) query("max_gin");
        kee = (int) query("max_kee");
        sen = (int) query("max_sen");
        if(!environment()->query("no_death_penalty"))
        set("combat_exp",exp/10 * 9);
        set("eff_kee",kee);
        set("eff_gin",gin);
        set("eff_sen",sen);
        set("kee",kee);
        set("gin",gin);
        set("sen",sen);
        save(); 
        ::die();
}
void init()
{
        add_action("do_kill",({"kill","fight","steal"}));
        add_action("do_mount","mount");
        add_action("do_gongji","gongji");//叫坐骑去攻击 ok
        add_action("do_teach","teach");// 向坐骑传授武功  ok
        add_action("do_shape","shape");// 查看坐骑  ok
        add_action("do_dote","dote");// 宠爱pet  ok
        add_action("do_flog","flog");// 鞭打pet  ok
        add_action("do_cundang","cundang");// 宠物save ok
        add_action("do_feed","feed");// 喂养pet ok 
        add_action("do_peilian","peilian");// 陪练 ok
}

int do_mount(string arg)
{
     object me=this_object(),who=this_player(),env;
     if(!arg) return 0;
     env = environment(who);
     if(present(arg,env)!=me) return 0;
     if(me->query("owner")==who->query("id")) 
     {
     who->set_temp("pet",1);
     return 0;
     }
     message_vision("$n左躲右闪，$N累得满头大汗也没骑上去。\n",who,me);
     return 1;
}
int do_kill(string arg)
{       
        object me,who;
        string name,verb,what,obj;
        if (!arg) return 0;
        verb=query_verb();
        me=this_player();
        
        if(verb=="steal") {
          if(sscanf(arg, "%s from %s", what, obj)!=2 ) 
            return 0;
          }
        else obj=arg;

        if(!objectp(who=present(obj,environment(me))) 
           || !living(who)) return 0;

        if(who==this_object()) {
          switch(verb) {
            case "kill":
              tell_object(environment(this_object()),
                who->query("name")+"拼命地哭了起来：主人，"+
                me->query("name")+"要杀我．．．快回来呀！\n");
              break;
            case "fight":

              tell_object(environment(this_object()),
                who->query("name")+"哭了起来：主人，"+
                me->query("name")+"要抢我的糖吃．．．快回来呀！\n");
              break;
            case "steal":

              tell_object(environment(this_object()),
                who->query("name")+"哭了起来：主人，"+
                me->query("name")+"要偷吃我的糖！\n");
              break;
          }
        }
        command(verb);
        return 0;
}
void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;

        switch(verb) {
        case "kick":
                command("say 主人～～，主人～～，"  + ob->query("name") + "踢我耶！");
                command("kick " + ob->query("id"));
                        break;
        case "slap":
                command("say 主人～～，主人～～，"  + ob->query("name") +
"打我耶，好痛啊～～～～");
                command("slap " + ob->query("id"));
                        break;
        case "hit":
                command("pain " + ob->query("id"));
                        break;
        case "bite":
                command("face " + ob->query("id"));
                        break;  
        case "papaya":
                command("pout");
                        break;  
                }
}
void relay_whisper(object me, string msg)
{
        if (me->query("id")!=query("owner"))
        {
                message_vision((string)this_object()->query("name")
                        + "疑惑地看着$N。\n", me);
                return;
        }
        if( strsrch(msg, "chat") != -1 ||
            strsrch(msg, "sldh") != -1 ||
            strsrch(msg, "es") != -1 ||
            strsrch(msg, "rumor") != -1 ||  
            strsrch(msg, "xyj") != -1 ||  
            strsrch(msg, "tell") != -1 ||
            strsrch(msg, "follow") != -1 ||
            strsrch(msg, "apprentice") != -1 ||
            strsrch(msg, "answer") != -1 ||
            strsrch(msg, "recruit") != -1 )
                return;
        if (msg)
        {
                remove_call_out ("relaying");
                call_out ("relaying", 1+random(3), msg);
        }
}
void relaying (string msg)
{
        command (msg);
}
int do_teach(string arg)
{
         object me,who;
        int gin_cost,amount;
        int myskill, itskill;
        me = this_player();
          who = this_object();
        if(!myskill = me->query_skill(arg,1))
        return notify_fail("这项技能你好象还不会呢！\n");
        if(arg != "unarmed" && arg != "parry" && arg != "dodge")
        return notify_fail("它学不会这项技能的！\n");
          if(who->query("owner")==me->query("id")) {
        itskill = query_skill(arg,1);
        if(myskill <= itskill)
        return notify_fail(name()+"以嘲笑的目光望着你。\n");
        if((int)me->query("potential")-(int)me->query("learned_points") < 1)
        return notify_fail("你的潜能不够！\n");
        gin_cost = 100/ (int)me->query_int();
        if((int)me->query("gin") < gin_cost)
        return notify_fail("你显然太累了没有办法教！\n");
        me->receive_damage("gin",gin_cost);
        me->add("potential",-1);
        amount = (int)me->query_int() * (int)me->query_int()/100;
        message_vision(sprintf("$N不厌其烦地教$n「%s」。\n",to_chinese(arg)),me,this_object());
        
        improve_skill(arg,amount);
        message_vision(sprintf("$N似乎真的学会了一些「%s」！\n",to_chinese(arg)),this_object());
          }
        return 1;
}
string status_color(int current, int max)
{
        int percent;

        if( max>0 ) percent = current * 100 / max;
        else percent = 100;
        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return RED;
}
int do_shape(string arg)
{
          object me,who;
          me = this_player();
          who = this_object();
          if(who->query("owner")==me->query("id"))
           {       mapping my;
        string shape;
        int at_pt,pa_pt,do_pt;
        my = query_entire_dbase();
        if((int)query("tonicity")>(int)query("sloth"))
        set("str",3+((int)query("tonicity")-(int)query("sloth"))/100);//膂力
        if((int)query("zhongcheng")>(int)query("sloth"))
        set("cor",3+((int)query("zhongcheng")-(int)query("sloth"))/100);//凶性
        set("ride/dodge", 20+(int)query_skill("dodge",1)/2);
        set_temp("apply/attack", 60+query("tonicity")/100);
        set_temp("apply/armor", 60+query("cool")/100);
        printf("精：%s%3d/ %3d %s(%3d%%)"NOR"  气：%s%3d/ %3d %s(%3d%%)"NOR"  神：%s%3d/ %3d %s(%3d%%)\n"+NOR,
                status_color(my["gin"], my["eff_gin"]), my["gin"],my["eff_gin"],
                status_color(my["eff_gin"], my["max_gin"]),     my["eff_gin"] * 100 / my["max_gin"],
                status_color(my["kee"], my["eff_kee"]), my["kee"], my["eff_kee"],
                status_color(my["eff_kee"], my["max_kee"]),     my["eff_kee"] * 100 / my["max_kee"],
                status_color(my["sen"], my["eff_sen"]), my["sen"], my["eff_sen"],
                status_color(my["eff_sen"], my["max_sen"]),     my["eff_sen"] * 100 / my["max_sen"]
        );              
        printf("主人： %s\t经验： %d\t道行： %d\n",
        my["owner"], my["combat_exp"],my["daoxing"]
        );
        printf("膂力： %d\t胆识： %d\t定力： %d\t根骨： %d\n",
        query_str(), query_cor(),query_cps(),query_con(),
        );
        printf("冷静： %d\t强壮： %d\t懒惰： %d\t忠诚： %d\n",
        query("cool"),query("tonicity"), query("sloth"),query("zhongcheng"),
        );
        at_pt= COMBAT_D->skill_power(this_object(), "unarmed", 1)/100;
        pa_pt= COMBAT_D->skill_power(this_object(), "unarmed", 2);
        do_pt= COMBAT_D->skill_power(this_object(), "dodge", 2);
        printf("攻击力： %d 防御力： %d 附加攻击： %d\t附加防御： %d\n\n",
        at_pt+1, pa_pt/2+do_pt/2+1,query_temp("apply/attack"),query_temp("apply/armor")
        );
        printf("/cmds/usr/skillspet"->pet_skill(this_object()));
          }
        return 1;
}
int do_cundang()
{	
        object pet,me;
        pet=this_object();
	me=this_player();
	if(pet->query("owner")==me->query("id"))
	 { 
        	if(pet->save()) message_vision("$N存档成功!\n",pet);
        	else message_vision("$N存档失败!\n",pet);
         }
        else write(HIW"这里有你的宠物?\n"NOR);
        return 1;
}

int do_feed()
{
       object me;
       //object feeob;
       int petskill;
       object pet = this_object();
       me = this_player();
        //if ( !arg || !(feeob=present(arg, me)) )
        //   return notify_fail("你要给它喂什么吃？\n");
        //else if (arg != "grass") 
        //   return notify_fail("这东西宠物吃不了。\n");  
      if(block(me,pet))
        { 
                if (me->query("kee")>50)  me->add("kee",-50); 
                else
                   {
                   message_vision("$N训练过度，心里交瘁，晕了。\n", me,pet);
                   me->unconcious();
                   return 1;
                   }
         //       destruct(feeob);
                message_vision("$N给$n喂了一些食物，$n津津有味的吃了起来。\n", me,pet);
                me->start_busy(random(2)+1);
                if ( random(5) != 0 )
                {
                pet->add("zhongcheng",random(5)+1);
                message_vision("$n亲昵地靠近$N,$n的忠诚度增加了.\n",me,pet);
                       if(random(50)==0)
                       {
                       petskill=pet->query_skill("dodge",1);
                       petskill-=1;
                       if (petskill<0) petskill=0;
                       pet->set_skill("dodge",petskill);
                       message_vision("$N吃太多而发胖了。\n",pet);
                       }
                }
                else
                  {
                  pet->add("zhongcheng",-random(10));
                  if(pet->query("zhongcheng")<0) pet->set("zhongcheng",0);
                  message_vision("$n吃了坏东西,拉肚子了.生气地看着$N。\n",me,pet);
                  }
       }
      return 1;
}

int do_dote()
{
       object me;
       object pet = this_object();
       me = this_player();
       if(block(me,pet))
        { 
                if (me->query("kee")>50)  me->add("kee",-50); 
                else
                   {
                   message_vision("$N训练过度，心里交瘁，晕了。\n", me,pet);
                   me->unconcious();
                   return 1;
                   }
                message_vision("$N宠爱地拍了拍$n的头，牵着它散步。\n", me,pet);
                me->start_busy(random(2)+1);
                if ( random(5) != 0 )
                {
                pet->add("zhongcheng",random(20)+1);
                message_vision("$n亲昵地靠近$N,$n的忠诚度增加了。\n",me,pet);
                       if(random(50)==0)
                       {
                       if(pet->query("zhongcheng")>49) pet->add("zhongcheng",-50);
                       else pet->set("zhongcheng",0);
                       message_vision("$N心情不好，不理你了。\n",pet);
                       }
                }
                else
                  {
                  pet->add("sloth",random(10));
                  message_vision("$n变懒了。\n",me,pet);
                  }
       }
      return 1;
}

int do_flog()
{
       object me;
       object pet = this_object();
       me = this_player();
       if(block(me,pet))
        { 
                if(random(pet->query("zhongcheng"))<20)
                   {
                   me->star_busy(2);
                   message_vision("$n似乎不太听$N的话了。\n", me,pet);
                   return 1;
                   }
                
                if (me->query("kee")>100)  me->add("kee",-100); 
                else
                   {
                   message_vision("$N训练过度，心里交瘁，晕了。\n", me,pet);
                   me->unconcious();
                   return 1;
                   }
                message_vision("$N威严地看着$n，手中鞭子毫不留情地鞭打$n。\n", me,pet);
                me->start_busy(random(2)+1);
                if ( random(5) != 0 )
                {
                pet->add("cool",random(15)+1);
                pet->add("zhongcheng",-1);
                pet->add("combat_exp",random(10)+1);
                message_vision("$n吃力地左挪右闪，看来经验增加了。\n",me,pet);
                       if(random(50)==0)
                       {
                       if(pet->query("zhongcheng")>49) pet->add("zhongcheng",-50);
                       else pet->set("zhongcheng",0);
                       message_vision("$N被你打怕了，对你很失望。\n",pet);
                       }
                }
                else
                  {
                  pet->add("cool",-random(10));
                  message_vision("$n训练过度，身体状况欠佳了。\n",me,pet);
                  }
       }
      return 1;
}

int do_peilian()
{
       object me;
       object pet = this_object();
       me = this_player();
       if(block(me,pet))
        { 
               if(random(pet->query("zhongcheng"))<20)
                   {
                   me->star_busy(2);
                   message_vision("$n似乎不太听$N的话了。\n", me,pet);
                   return 1;
                   }
               if (me->query("kee")>200)  me->add("kee",-200); 
                else
                   {
                   message_vision("$N训练过度，心里交瘁，晕了。\n", me,pet);
                   me->unconcious();
                   return 1;
                   }
                message_vision("$N把$n带到训练场，亲自和$n一起练功。\n", me,pet);
                me->start_busy(random(2)+1);
                if ( random(5) != 0 )
                {
                pet->add("tonicity",random(15)+1);
                pet->add("sloth",random(3));
                pet->add("daoxing",random(10)+1);
                message_vision("$n经过训练，更加强壮了。\n",me,pet);
                       if(random(50)==0)
                       {
                       if(pet->query("zhongcheng")>49) pet->add("zhongcheng",-50);
                       else pet->set("zhongcheng",0);
                       message_vision("$N累得半死，对你的忠诚度降低了。\n",pet);
                       }
                }
                else
                  {
                  pet->add("zhongcheng",-random(10));
                  message_vision("$n训练过度，开始不开心了。\n",me,pet);
                  }
       }
      return 1;
}
