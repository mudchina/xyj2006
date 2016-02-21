inherit NPC;

void init_skill(int exp,int daoxing,int skillmax,int max_kee,int max_force,int max_sen,int max_mana,string type);
int my_randommove();

void create()
{
  set("bad",1);
   set_name("野猪怪", ({"yezhu guai"}) );
   if(random(2)) set("gender", "男性" );
   else set("gender","女性" );
   
   set("age", 30);
   set("long", "\n");
   set("attitude", "heroism");

   set("chat_chance_combat", 50);

   set("str", 40);
   set("cor", 25);
   set("cps", 25);
   set("int", 25);
   set("chat_chance", 5);
   set("chat_msg", ({
      (: my_randommove :),
        }));

    setup();
    add_money("silver",50);
}

void init_skill(int exp,int daoxing,int skillmax,int max_kee,int max_force,int max_sen,int max_mana,string type)
{
        object weap;
         
 set_skill("force",skillmax+random(skillmax/20));
 set_skill("parry",skillmax+random(skillmax/20));
 set_skill("dodge",skillmax+random(skillmax/20));
 set_skill("spells",skillmax+random(skillmax/20));
 if(type=="mo")
 switch(random(4)){
        case 0:
            set("chat_msg_combat", ({
                 (: perform_action,"stick","pili" :),
                 (: cast_spell, "thunder" :),
		 (: cast_spell, "light"   :),
             }));
  
             set_skill("stick",skillmax+random(skillmax/20));
             set_skill("unarmed",skillmax+random(skillmax/20));
             set_skill("puti-zhi",skillmax+random(skillmax/20));
             set_skill("qianjun-bang",skillmax+random(skillmax/20));
             set_skill("spells",skillmax+random(skillmax/20));
             set_skill("dao",skillmax+random(skillmax/20));
             set_skill("dodge",skillmax+random(skillmax/20));
             set_skill("jindouyun",skillmax+random(skillmax/20));
             set_skill("force",skillmax+random(skillmax/20));
             set_skill("parry",skillmax+random(skillmax/20));
             set_skill("wuxiangforce",skillmax+random(skillmax/20));
             map_skill("force","wuxiangforce");
             map_skill("spells", "dao");
             map_skill("stick", "qianjun-bang");
             map_skill("parry", "qianjun-bang");
             map_skill("unarmed","puti-zhi");
             map_skill("dodge", "jindouyun");
             weap=new("/d/lingtai/obj/bang.c");
             weap->move(this_object());
             weap->wield();
             break;
         case 1:
            set("class","xian");
          
  set("chat_msg_combat", ({
               (: cast_spell, "shiyue" :),
               (: perform_action,"sword","wuxue" :),
            }));
           set_skill("sword",skillmax+random(skillmax/20));
           set_skill("snowsword",skillmax+random(skillmax/20));
           set_skill("spells",skillmax+random(skillmax/20));
           set_skill("moonshentong",skillmax+random(skillmax/20));
           set_skill("parry",skillmax+random(skillmax/20));
           set_skill("dodge",skillmax+random(skillmax/20));
           set_skill("moondance",skillmax+random(skillmax/20));
           set_skill("moonforce",skillmax+random(skillmax/20));
           set_skill("force",skillmax+random(skillmax/20));
           set_skill("unarmed",skillmax+random(skillmax/20));
           set_skill("baihua-zhang",skillmax+random(skillmax/20));
           
           map_skill("spells", "moonshentong");
           map_skill("sword", "snowsword");
           map_skill("parry", "snowsword");
           map_skill("dodge", "moondance");
           map_skill("force","moonforce");
           map_skill("unarmed","baihua-zhang");

           weap=new("/d/obj/weapon/sword/changjian.c");
           weap->move(this_object());
           weap->wield();   
    
       break;
         case 2:
           set("chat_msg_combat", ({
             (: perform_action,"staff", "qifei" :),
            (: cast_spell, "bighammer" :),
           }));

           set_skill("staff",skillmax+random(skillmax/20));
           set_skill("lunhui-zhang",skillmax+random(skillmax/20));
           set_skill("spells",skillmax+random(skillmax/20));
           set_skill("buddhism",skillmax+random(skillmax/20));
           set_skill("dodge",skillmax+random(skillmax/20));
           set_skill("lotusmove",skillmax+random(skillmax/20));
           set_skill("lotusforce",skillmax+random(skillmax/20));
           set_skill("unarmed",skillmax+random(skillmax/20));
           set_skill("jienan-zhi",skillmax+random(skillmax/20));
           
           map_skill("spells", "buddhism");
           map_skill("staff", "lunhui-zhang");
           map_skill("parry", "lunhui-zhang");
           map_skill("dodge", "lotusmove");
           map_skill("force","lotusforce");
           map_skill("unarmed","jienan-zhi");

           weap=new("/d/obj/weapon/staff/muzhang.c");
           weap->move(this_object());
           weap->wield();   
           break;
         case 3:
           set("class","dragon");
           set("chat_msg_combat", ({
              (: cast_spell, "breathe" :),
              (: exert_function, "roar" :),
              (: exert_function, "shield" :),
              (: cast_spell, "freez" :),
           }));
         
           set_skill("fork",skillmax+random(skillmax/20));
           set_skill("fengbo-cha",skillmax+random(skillmax/20));
           set_skill("spells",skillmax+random(skillmax/20));
           set_skill("seashentong",skillmax+random(skillmax/20));
           set_skill("dodge",skillmax+random(skillmax/20));
           set_skill("dragonstep",skillmax+random(skillmax/20));
           set_skill("dragonforce",skillmax+random(skillmax/20));
           set_skill("unarmed",skillmax+random(skillmax/20));
           set_skill("dragonfight",skillmax+random(skillmax/20));
        
           map_skill("spells", "seashentong");
           map_skill("fork", "fengbo-cha");
           map_skill("parry", "fengbo-cha");
           map_skill("dodge", "dragonstep");
           map_skill("force", "dagonforce");
           map_skill("unarmed","dragonfight");

           weap=new("/d/sea/obj/tuotiancha.c");
           weap->move(this_object());
           weap->wield();   
           break;
       }
  else
    switch(random(3)){    
           case 0:
            set("chat_msg_combat", ({
            (: perform_action,"sword", "chaofeng" :),
	    (: cast_spell, "juanbi" :),
            }));

           set_skill("sword",skillmax+random(skillmax/20));
           set_skill("bainiao-jian",skillmax+random(skillmax/20));
           set_skill("spells",skillmax+random(skillmax/20));
           set_skill("dodge",skillmax+random(skillmax/20));
           set_skill("xiaoyaoyou",skillmax+random(skillmax/20));
         
  	   set_skill("ningxie-force",skillmax+random(skillmax/20));     
           set_skill("unarmed",skillmax+random(skillmax/20));    
           set_skill("yingzhaogong",skillmax+random(skillmax/20));

           map_skill("spells", "dengxian-dafa");
           map_skill("sword", "bainiao-jian");
           map_skill("parry", "bainiao-jian");
           map_skill("dodge", "xiaoyaoyou");
           map_skill("force","ningxie-force");  
           map_skill("unarmed","yingzhaogong");
           
           weap=new("/d/obj/weapon/sword/changjian.c");
           weap->move(this_object());
           weap->wield();   
           break;

         case 1: 
           set("class","youling");
           set("chat_msg_combat", ({
            (: perform_action,"whip", "three" :),
            (: cast_spell, "gouhun" :),
           }));
        
          set_skill("whip",skillmax+random(skillmax/20));
          set_skill("hellfire-whip",skillmax+random(skillmax/20));
          set_skill("spells",skillmax+random(skillmax/20));
          set_skill("gouhunshu",skillmax+random(skillmax/20));
          set_skill("dodge",skillmax+random(skillmax/20));
          set_skill("ghost-steps",skillmax+random(skillmax/20));
          set_skill("tonsillit",skillmax+random(skillmax/20));
          set_skill("jinghun-zhang",skillmax+random(skillmax/20));
          set_skill("kusang-bang",skillmax+random(skillmax/20));
          set_skill("unarmed",skillmax+random(skillmax/20));
          set_skill("jinghun-zhang",skillmax+random(skillmax/20));

          map_skill("spells", "gouhunshu");
          map_skill("whip", "hellfire-whip");
          map_skill("parry", "hellfire-whip");
          map_skill("dodge", "ghost-steps");
          map_skill("force", "tonsillit");
          map_skill("unarmed","jinghun-zhang");
          weap=new("/d/obj/weapon/whip/whip.c");
          weap->move(this_object());
          weap->wield();                       
          break;                     

           case 2:
            set("chat_msg_combat", ({
            (: perform_action,"blade","pozhan" :),
            }));

           set_skill("blade",skillmax+random(skillmax/20));
           set_skill("kugu-blade",100);
           set_skill("unarmed",skillmax+random(skillmax/20));
           set_skill("yinfeng-zhua",skillmax+random(skillmax/20));
           set_skill("spells",skillmax+random(skillmax/20));
           set_skill("dodge",skillmax+random(skillmax/20));
           set_skill("lingfu-steps",skillmax+random(skillmax/20));
           set_skill("huntian-qigong",skillmax+random(skillmax/20));
           set_skill("yaofa", skillmax+random(skillmax/20));
           map_skill("spells", "yaofa");
           map_skill("blade", "kugu-blade");
           map_skill("dodge", "lingfu-steps");
           map_skill("force","huntian-qigong");
           map_skill("unarmed","yinfeng-zhua");
           weap=new("/d/obj/weapon/blade/blade.c");
           weap->move(this_object());
           weap->wield();
           break;


           case 3:
          set("chat_msg_combat", ({
                 (: perform_action, "stick","pili" :),
                 (: cast_spell, "thunder" :),
             }));

           set_skill("stick",skillmax+random(skillmax/20));
           set_skill("qianjun-bang",skillmax+random(skillmax/20));
           set_skill("dodge",skillmax+random(skillmax/20));
           set_skill("unarmed",skillmax+random(skillmax/20));
           set_skill("houquan",skillmax+random(skillmax/20));
           set_skill("balei",skillmax+random(skillmax/20));
           set_skill("throwing",skillmax+random(skillmax/20));
           set_skill("huntian-qigong",skillmax+random(skillmax/20));
           set_skill("yaofa", skillmax+random(skillmax/20));
           map_skill("dodge", "baieli");
           map_skill("force","huntian-qigong");
           map_skill("unarmed","houquan");
           map_skill("stick","qianjun-bang");           
           weap=new("/d/lingtai/obj/bang.c");
           weap->move(this_object());
           weap->wield();
           break;

  }       
   max_kee=3*max_kee/2;
   max_sen=max_sen;
  set("max_kee",max_kee);
if (max_mana<30*skillmax/2) max_mana=25*skillmax/2;
   set("kee",max_kee);
   set("eff_kee",max_kee);
   set("max_sen",max_sen);
   set("eff_sen",max_sen);
   set("sen",query("max_sen"));
   set("max_force", max_force);
   set("max_mana",  max_mana);
   set("force_factor", query("max_force")/100);
   set("mana_factor",  query("max_mana")/100);
   set("force",  query("max_force"));
   set("mana",  query("max_mana"));
   set("combat_exp", exp );
   set("daoxing",daoxing);

   set("new_time",time());
   return ;
}

   int heal_up()
{
  if( environment() && time()-query("new_time")>480&&!is_fighting()) {
    call_out("leave", 1);
    return 1;
  }
  return ::heal_up() + 1;
}

void leave()
{
    object me=query("pre_killer");
    tell_room(environment(),query("name")+"逃跑拉！\n");
    destruct(this_object());
}

int my_randommove()
{
   mapping exits;
   string *dirs;
   string ldir;
   string* loclist;
   string* loclist2;
   
   int size; 

   if( !mapp(exits = environment()->query("exits")) ) return 0;
   dirs = keys(exits);
   size=sizeof(dirs);
   if(size>0){
     ldir=dirs[random(size)];
     loclist=explode(exits[ldir],"/");
     loclist2=explode(file_name(environment()),"/");
     if(loclist[sizeof(loclist)-2]==loclist2[sizeof(loclist2)-2])
       return command("go " + ldir);
   }
   return 0;
}
