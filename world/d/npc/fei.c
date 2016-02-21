
#include <ansi.h>

inherit NPC;

int random_place(object me, string dirs);
void _leave();
void leave();
void set_skills();

int announced=0;

string *dirs = ({
"/d/xueshan",
"/d/lingtai",
"/d/moon",
"/d/nanhai",
"/d/death",
"/d/pansi",
"/d/jjf",
"/d/sea",
"/d/qujing/wudidong",
"/d/qujing/wuzhuang",
"/d/qujing/kusong",
"/d/qujing/shushan",
"/d/qujing/changan",
"/d/qujing/wuji",
"/d/qujing/baoxiang",
"/d/qujing/tianzhu",
"/d/qujing/nuerguo",
"/d/qujing/yuhua",
  
});

void create()
{
        seteuid(getuid());
        set_name("盗宝飞贼",({"zei"}));
//	mapping name;
	
//	name=NAME_D->random_name("yaoguai");
//	set_name(name["name"], name["id"]);
//    set("title", HIB"天庭通缉盗宝贼"NOR);
        set("age",30);
 
        set("str",30);
        set("per",20);
        set("combat_exp",5000);
        set("attitude", "heroism");
        set_skill("unarmed",200);
        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :)
        }));
        setup();
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        carry_object("/d/obj/drug/jinchuang");
        add_money("gold", 5);
}

void init()
{
    object me=this_object();
    object who=this_player();
    int type;
    int t=query("stay_time");

    ::init();
    
    if(t && time()>(t+300)) {
        remove_call_out("leave");
        call_out("leave",1);
        return;
    }

    if(t && time()>t) {
        remove_call_out("_leave");
        call_out("_leave",300);
    }
    if(!living(this_object())) return;
    if(!living(who)) return;
    remove_call_out("check_room");
    call_out("check_room",2);
}

void check_room()
{
    object me=this_object();
    object env=environment(me);
    if(!living(me)) return;
    if(env && (env->query("no_fight") ||
                env->query("no_magic"))) {
        random_move();
    }
}

void copy_status(object me)
{
        object *inv;
        mapping skill_status,map_status;
        string *sname,*mname;
        int i, eff_dx, nk_factor;
			mapping name;
	
	name=NAME_D->random_name("yaoguai");
	set_name(name["name"], name["id"]);
    set("title", HIB"天庭通缉盗宝贼"NOR);

//        set_name("飞贼",({"fei zei","zei"}));
//        set("title",query("target")+"盗宝飞贼");
        set("enable_type","飞贼");
        set("str",30);
        set("int",30);
        set("con",30);
        set("per",30);
        set("cor",30);
        set("spi",30);
        set("cps",30);
        set("kar",30);

        set("max_kee",3000+random(1000));
        set("eff_kee",3000+random(1000));
        set("kee",3000+random(1000));

        set("max_gin",2000+random(1000));
        set("eff_gin",2000+random(1000));
        set("gin",2000+random(1000));

        set("max_sen",2000+random(1000));
        set("eff_sen",2000+random(1000));
        set("sen",2000+random(1000));

        set("max_force",3000+random(1000));
        set("force",6000+random(1000));
        set("force_factor",300);

        set("max_mana",3000+random(1000));
        set("mana",6000+random(1000));
        set("mana_factor",300);
        set("combat_exp",500000+random(1000000));
        set("daoxing",100000+random(300000));

        set("stay_time",time()+600+random(60));
        set("nk_gain", 100+random(50));
        set("nk_factor", 12);

        
        set("bellicosity",300);
        carry_object("/d/qujing/jindou/obj/boots")->wear();
        carry_object("/d/qujing/jindou/obj/finger")->wear();
        carry_object("/d/qujing/jindou/obj/hands")->wear();
        carry_object("/d/qujing/jindou/obj/head")->wear();
        
        set_skills();

        //carry_object("/d/obj/drug/jinchuang");       
        reset_eval_cost();
}

int invocation(int i)
{
        object me=this_object();
        copy_status(me);
        if(!random_place(me, dirs[i]))
        return 0;
        return 1;
}


int random_place(object me, string dirs)
{
        int  j, k;
        object  newob;
        mixed*  file, exit;
        file = get_dir( dirs+"/*.c", -1 );

        if( !sizeof(file) )             return 1;

        for(k=0;k<30;k++) { // try 30 times
           j = random(sizeof(file));
           if( file[j][1] > 0 ) {
             newob=load_object(dirs+"/"+file[j][0]);
             if (newob) {  
               if(newob->query("no_fight") ||
                       newob->query("no_magic") ||
                       !(exit=newob->query("exits")) ||
                       sizeof(exit)<1)
                   continue;

               if(me->move(newob)) {
                   message_vision("$N走了过来。\n",me);
                   return 1;
               }
             }
           }
        }

        return 0;
}



varargs int receive_damage(string type, int damage, object who)
{
  object me=this_object();
  call_out("exertheal",1,me);
  return ::receive_damage(type,damage,who);
}

void exertheal(object me) 
{
  me->command("exert recover");
}

void die()
{

        int reward;
        object ob,me;
        ob = query_temp("last_damage_from");
        me=this_object();
        if (!ob)
        {
                leave();
                return; 
        }
        CHANNEL_D->do_channel( this_object(), "rumor",
        sprintf("盗宝%s的"NOR+HIW"%s"HIM"被"HIY"%s"HIM"就地正法了。"NOR,query("target"),query("name"), ob->name() ));
        reward = query("nk_gain") * query("nk_factor");
        ob->add("kill/nkgain",reward);
        ob->add("daoxing",reward);
        ob->add("potential", reward*2/3);
        tell_object(ob,"\n你杀死盗宝妖怪,天庭特赐你"+COMBAT_D->chinese_daoxing(reward)+"道行和"
                + reward/2 + "点潜能！\n" );
        MONITOR_D->report_system_object_msg(ob,"得到了"+COMBAT_D->chinese_daoxing(reward)+"道行和"

                + reward/2 + "点潜能！");
        ::die();
}

void unconcious()
{
  if (query("kee")<0 || query("sen")<0) die();
   else ::unconcious();
}

void heart_beat()
{
        if (!query_temp("weapon") && !query_temp("added"))
        {
        set_temp("added", 1);
        set("force_factor",100);
        set("force",2000);
        }
        if (query("eff_kee")<query("max_kee"))
        {
        if (random(10))
        command("eat yao");

        else
        {
                command("surrender");
                call_out("exertheal",1,this_object());
        }
        }


        ::heart_beat();
}

void _leave()
{
        object me=this_object();
        if(me->is_fighting() || me->is_busy())
        return;
        leave();
}

void leave()
{
      if(this_object()) {
        if(environment())
{
command("say 嘿嘿，躲了这么久了，看来是风平浪静了。。。");
          message("vision",HIB + name() + 
                  "身子一晃，变成一股青烟散去了。\n" NOR,environment());
}
        destruct(this_object());
      }
      return;
}

int attack()
{
        object opponent;
        clean_up_enemy();
        opponent = select_opponent();
        if( objectp(opponent) ) {
        if(opponent->query("family/family_name")==this_object()->query("target")
                        && userp(opponent)
                        && !living(opponent)
                        && environment()==environment(opponent)) {
                    call_out("leave",1);
                    return 0;
                }

                set_temp("last_opponent", opponent);
                COMBAT_D->fight(this_object(), opponent);
                return 1;
        } else
                return 0;
}

