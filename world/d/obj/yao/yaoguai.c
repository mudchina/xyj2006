inherit NPC;
inherit __DIR__"yaoguai_reward.c";

#include <ansi.h>

#define SHILI_D "/adm/daemons/shili"

string _invocation(object who, int level, string loc);
int exp_reward, pot_reward;
int other_kee=0, other_sen=0;

string *death_msg= ({
HIB"\n$n大叫一声“这次是你赢了，下次我们走着瞧。。。”\n$n说完，化做一道青光，直冲云霄去了．．．\n"NOR,
HIY"\n$N喝道：那里走！\n$n无可奈何，往地下一钻，就消失了。\n"NOR,
WHT"\n$n惨叫一声，死了。\n"NOR,
});

int random_place(object me, string loc);
int strength();
void leave();

int cast_chance(int level) 
{
    return 10+level/2;
}

// here should be this NPC specific skills.
void set_skills(int j, int level)
{
}

void copy_status(object me,object ob, int lv)
{
        int j, lvl;

        int base=20;

        mapping skill=ob->query_skills();
        int i=sizeof(skill);
        string* key;
        int max_level;
        int max_sen, max_kee;

        lvl=lv+base-2;
        
            if(i>0) {
                key=keys(skill);
                max_level=skill[key[0]];
                while(i--) { // find out victim's maximum level
                    if(skill[key[i]]>max_level&&key[i]!="literate")
                        max_level=skill[key[i]];
                }
                max_level=max_level*lvl/base;

            } else max_level=1;

       max_sen=ob->query("max_sen")*(1000+max_level)/1000;
         max_kee=ob->query("max_kee")*(200+max_level)/200;

            // skill level will be set to the maximum level
            // of the player.
            set("eff_sen",max_sen);
            set("eff_kee",max_kee);
            set("sen",max_sen);
            set("kee",max_kee);
            set("max_sen",max_sen);
            set("max_kee",max_kee);
            
             max_kee=ob->query("max_force");
             max_sen=ob->query("max_mana");
            set("max_force",max_kee);
            set("force",max_kee);
            set("force_factor",max_kee/50);
            set("max_mana",max_sen);
            set("mana",max_sen);
            set("mana_factor",max_sen/50);
        set("combat_exp",ob->query("combat_exp")*lvl/20);
            
            set_skills(max_level, lv);
}

int random_place(object me, string loc)
{
        int  j, k;
        object  newob;
        mixed*  file, exit;

        file = get_dir( loc+"/*.c", -1 );
        if( !sizeof(file) )             return 1;

        for(k=0;k<30;k++) { // try 20 times
           j = random(sizeof(file));
           if( file[j][1] > 0 ) {
             newob=load_object(loc+"/"+file[j][0]);
             if (newob) {  
               if(newob->query("no_fight") ||
                       newob->query("no_magic") ||
                       newob->query("alternative_die") ||
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

void leave()
{
      if(this_object()) { 
        if(environment())
          message("vision",HIB + name() + 
                  "身子一晃，变成一股青烟散去了。\n" NOR,environment());
        destruct(this_object());
      }
      return;
}

string invocation(object who, int level,string loc)
{
        object me=this_object();

        copy_status(me,who, level-2);
        carry_object("/d/obj/armor/yinjia")->wear();
        
        return _invocation(who, level, loc);
}

string _invocation(object who, int level,string loc)
{       object me=this_object(), env;
        string *dirs; 
        int dx, i, lvl;
        int exp;
        string where, guainame,title;
        title="";
        
        set("owner", who->query("id"));
        set("owner_ob", who);

        dx=me->query("combat_exp");
            
        if(dx>=10000000)
        title=title+HIY"万年"NOR;
        else if(dx>=1000000)
        title=title+HIW"千年"NOR;
        else if(dx>=100000)
        title=title+HIB"百年"NOR;
        else if(dx>10000)
        title=title+WHT"十年"NOR;
        else
        title=title+MAG"小小"NOR;
            
            set("title",title);

        lvl=level;
        
        if(random(10)==0) {
            set("env/wimpy",40);
            if(lvl<9) lvl=lvl+1; // as more difficult to kill.
        } else {
            set("env/wimpy",1);
        }

        // determine reward
        exp=who->query("combat_exp");
        
        if(exp<30000) {
            exp_reward=80+exp/60;
            pot_reward=30+exp/300;
        } else if(exp<300000) {
            exp_reward=180+exp/600;
            pot_reward=40+exp/6000;
        } else if(exp<3000000) {
            exp_reward=230+exp/6000;
            pot_reward=50+exp/60000;
        } else {
            exp_reward=280+random(500);
            pot_reward=70+random(100);
        }

        pot_reward=pot_reward*(lvl+1)/10;
        exp_reward=exp_reward*(lvl+1)/10;

        me->set("stay_time", time()+600);
        who->set("mieyao_time",time());

        if(!random_place(me, loc)) {
            leave();
            return 0;
        }
        
        env=environment(me);
        guainame=me->query("name")+"("+me->query("id")+")";
        where=guainame;
        if(env)
          where+="在"+SHILI_D->query_chinese(query("pos"));
        return where;
}
/*
void check_room()
{
    object me=this_object();
    object env=environment(me);
    
    if(!living(me)) return;
    if(env && (env->query("no_fight") ||
                env->query("no_magic")||
                env->query("alternative_die"))) {
        random_move();
    }
}
*/
void unconcious()
{
  die();
}

void die()
{
        string owner;
        string skill;
        object owner_ob;
        object me=this_object();
        string msg;
        int max_kee, max_sen, ratio, exp_r, pot_r;

        owner = query("owner");

        if( stringp(owner) && objectp(owner_ob = find_player(owner)) ) {
            if(environment(owner_ob)==environment() && living(owner_ob)) {
              message_vision(death_msg[random(sizeof(death_msg))],owner_ob,this_object());
            } else {
                message_vision("$N死了。\n",this_object());
            }
            owner_ob->delete("mieyao");
                    
                    max_kee=query("max_kee");
                    max_sen=query("max_sen");
                    ratio=100*(max_kee-other_kee)/max_kee;
                    if(ratio<0) ratio=0;
                    ratio=ratio*(max_sen-other_sen)/max_sen;
                    if(ratio<0) ratio=0;
                   ratio=ratio*(2+query("bian_num"))/2;
    
                    exp_r=exp_reward*ratio/100;
                    pot_r=pot_reward*ratio/100;
                    owner_ob->add("combat_exp",exp_r);
                    owner_ob->add("potential",pot_r);
                  owner_ob->add("faith",ratio/100);
    SHILI_D->increase_shili(query("pos"),owner_ob->query("family/family_name"),1);
                    
         if (owner_ob->query_temp("mieyao/level")==9) {
          skill=give_reward(owner_ob);
          }

          tell_object(owner_ob, HIR"\n你得到了"NOR+FLA+COMBAT_D->chinese_daoxing(exp_r)
             +NOR+HIY"道行和"NOR+FLA+chinese_number(pot_r)+NOR+ HIY"点潜能！\n"NOR);
       } else {
            message_vision("$N死了。\n",this_object());
       }

    destruct(this_object());

}


// This is called in heart_beat() to perform attack action.
int attack()
{
        object opponent;

        clean_up_enemy();

        opponent = select_opponent();
        if( objectp(opponent) ) {
                string owner=query("owner");
                
                // if the owner faints, then will not attack
                // and leave. -- mon 3/8/99
                if(opponent->query("id")==owner 
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

int accept_fight(object me)
{
     kill_ob(me);     
     return 1;
}

int heal_up()
{
    object weapon;
 
    if(!random(5)&&time()>query("stay_time")&&!is_fighting())
        leave();
//        check_room();

      if(!random(3)&&!query_temp("weapon")&&query("weapon_")){
     weapon=new(query("weapon_"));
     weapon->move(this_object());
     command("wield all");
    }
    return ::heal_up()+1;
}

int strength()
{
    string* ycolor=({NOR,BLK,RED,YEL,BLU,MAG,CYN,WHT,HIR,HIG,
      HIY,HIB,HIM,HIC,HIW});   
    int i;  
      
    if(!random(2)&&is_fighting()&&query("kee")*100/query("max_kee")<50){
         tell_room(environment(),query("name")+"仰天大叫："+RED+"上苍赐我力量！"+NOR+"\n转眼变得精神抖擞起来。\n");
         i=query("bian_num")+1;
         set("bian_num",i);
         if(i==sizeof(ycolor))i=1;
         set("name",ycolor[i]+query("name")+NOR);
         set("eff_kee",query("max_kee"));                       
         set("eff_sen",query("max_sen"));
         set("kee",query("max_kee"));
         set("sen",query("max_sen"));
         set("force",query("max_force")*(60+i)/50);
         set("mana",query("max_mana")*(60+i)/50);
         set("force_factor",query("max_force")*(i+4)/200);
         set("mana_factor",query("max_mana")*(i+4)/200);          
    }     
}

varargs int receive_wound(string type, int damage, object who)
{
    string owner=query("owner");
    
    if(who && who->query("id")!=owner && userp(who)) {
        if(damage>0) {
            switch(type) {
                case "kee": other_kee+=damage; break;
                case "sen": other_sen+=damage; break;
            }
        }
    }
    return ::receive_wound(type, damage, who);
}

varargs int receive_damage(string type, int damage, object who)
{
    string owner=query("owner");
    
    if(who && who->query("id")!=owner && userp(who)) {
        if(damage>0) {
            switch(type) {
                case "kee": other_kee+=damage; break;
                case "sen": other_sen+=damage; break;
            }
        }
    }
    return ::receive_damage(type, damage, who);
}
