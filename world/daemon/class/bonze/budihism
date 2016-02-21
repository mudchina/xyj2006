// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// pudu.c 普渡慈航
// by New moon 
// 2000-09-20

#include <ansi.h>

inherit SSERVER;

string remove_ansi(string str)
{
        int i;
        string *color = ({ BLK, RED, GRN, YEL, BLU, MAG, CYN, WHT,
                        HIR, HIG, HIY, HIB, HIM, HIC, HIW,
                        HBRED, HBGRN, HBYEL, HBBLU, HBMAG, HBCYN, HBWHT,
                        BBLK, BRED, BYEL, BBLU, BMAG, BCYN,
                        NOR, BOLD,BLINK });
                        
        if( str && stringp(str) ) 
         {
            i = sizeof(color);
          while( i-- ) {
              str = replace_string(str, color[i], "");
         };
          return str;
         }
}


int cast(object me, object target)
{
   string msg,spells_skill,name;
   int ap,dp,ap1,dp1,pp,i,j,p;
   object weapon,*inv;

   if( !target ) target = offensive_target(me);

   if((int)me->query_skill("spells") < 100 || (int)me->query_skill("buddhism",1) < 100)
     return notify_fail("你还没学会[普渡慈航]。。。\n");

   if (me->query("env/invisibility")) 
     return notify_fail("你不现法身，如何点化世人？\n");
   
   if( !target
   ||      !target->is_character()
   ||      target->is_corpse()
   ||      target==me)
     return notify_fail("你想点化谁？\n");  
   
   if (!me->is_fighting() && (userp(target)))
      return notify_fail("天下本无事，何必自扰之？\n");
   
    if((int)me->query("mana") < 500 )
     return notify_fail("你的法力不够！\n");

   if((int)me->query("sen") < 200 )
     return notify_fail("你无法集中精力！\n");

   me->add("mana", -500);
   me->receive_damage("sen",200);

 

        if (!wizardp(me)&&me->query("family/family_name") != "南海普陀山")
         return notify_fail("你非佛门弟子，无法点化世人\n");
        
         if ( me->query_skill("buddhism",1)< 100) 
             return notify_fail("你还没有学会[普渡慈航]......\n");  
        spells_skill = target->query_skill_mapped("spells");
        ap = me->query_skill("spells") + me->query("cor");
        dp = target->query_skill("spells",1) + target->query("cps");
        ap1= me->query("cor");
        dp1= target->query("cps");
        if ((string)me->query("bonze/class") =="bonze" )
          pp = me->query_skill("buddhism",1)*2;
        weapon=target->query_temp("weapon");
        inv=all_inventory(me);
        i=sizeof(inv);
        me->delete_temp("condition/carrying_ok");
        j=0;
        while (i--)
        {  
        name = (string)(inv[i])->query("name");
        name = remove_ansi(name);
        if ( name == "锦澜袈裟" )
                    me->set_temp("condition/carrying_ok", 1);
            
         }      
        if ( !me->query_temp("condition/carrying_ok") 
           && ( userp(target)))
          pp = pp /2;
          
     if( !present(target, environment(me)) )
        return notify_fail("这次还是得饶人处且饶人吧。\n");
            
   if( random(ap+dp) > dp)
   {
    if((string)me->query("family/master_id") == "guanyin pusa" && random(ap1)>random(dp1) ) 
    { 
      msg = HIC"$N双手合十，两眼微闭，口中轻诵，全身都拢罩在一片霞光之中。但听$N念道：\n"NOR;          
      switch (random(3))
    {
     case 0:
      { msg += HIC"
    若恶兽围绕，利牙爪可怖，念彼观音力，疾走无边方。\n
    蟒蛇及螟蝎，气毒烟火然，念彼观音力，寻声自回去。\n
    云雷鼓掣电，降雹澍大雨，念彼观音力，应时得消散......\n"NOR; break;}
      
    case 1:
      { msg += HIC"
    众生被困厄，无量苦遍身，
    观音妙智力，能救世间苦......\n"NOR; break; }
    case 2:
      { msg += HIC"
    若有无量百千万亿众生，受诸苦恼，
    闻是观世音菩萨，一心称名，观世音菩萨即时观其音声，皆得解脱。
    若有持是观世音菩萨名者。设入大火，火不能烧，由是菩萨威神力故。
    若为大水所漂，称其名号，即得浅处......\n"NOR; break; }
    
      }
          
               
       if ( me->query_temp("condition/carrying_ok") )
            {                     
                               target->receive_damage("sen", pp*3);  
                               target->receive_wound("sen", pp*2);
                               target->add("mana",-200);
                               target->add("mana",-pp*2);
                             if (target->query("mana")<0) target->set("mana",0);
             }
         
           else {
                  target->receive_damage("sen", pp*3/2);  
                               target->receive_wound("sen", pp);
                               target->add("mana",-100);
                               target->add("mana",-pp);
                             if (target->query("mana")<0) target->set("mana",0);
                }
                      
       msg += HIR"不知不觉中$n竟然已泪流满面，喃喃地念到：罢了，罢了......\n"NOR;
               
       if(objectp(weapon) && ( me->query_temp("condition/carrying_ok") || random(10)>7 ) )
          {
            weapon->unequip();
            weapon->move(environment(target));  
            msg+="$n丢下手中的"+weapon->query("name")+"，叹道：“"+RANK_D->query_self(me)+"今日始闻大道，愿意依归我佛！\n"NOR;
          }
             message_vision(msg,me,target);         
             COMBAT_D->report_sen_status(target);
        }
    
                        else
                         {
                           msg = HIW"$N厉声喝道：放下屠刀，立地成佛！放下屠刀，立地成佛！！放下屠刀，立地成佛！！！\n"NOR;
                           if (random(ap1+ap1)>random(dp1)) 
                             {
                               msg += HIW"只见$n精神恍惚，身体摇摇欲坠！\n"NOR;
                               message_vision(msg,me,target);         
                               COMBAT_D->report_sen_status(target);
                               target->receive_damage("sen", pp);  
                               target->receive_wound("sen", pp/2);
                               target->add("mana",-100);
                               target->add("mana",-pp/2);
                               if (target->query("mana")<0) target->set("mana",0);
                              }
   
                              else {
                    if (spells_skill) {
       msg += HIW"$n默运"+CHINESE_D->chinese(spells_skill)+HIW"，一声大喝：何人在此装神弄鬼！\n"NOR;                             
       message_vision(msg,me,target);         
                 
       if ( !me->query_temp("condition/carrying_ok") )
           me->start_busy(2+random(3));
                                     } 
                                  }
                } 
   
        
          if( !target->is_fighting(me) )
            {
               if( living(target) )
                {
                    if( userp(target) ) target->fight_ob(me);
                        else
                 target->kill_ob(me);
                }
                me->fight_ob(target);
            }
             
                 return 3+random(4);
        }
   
         message_vision(HIR"$n哈哈大笑：“我命由我不由人，要你这"+RANK_D->query_rude(me)+"来唠叨些什么!\n"NOR,me,target);     
         
         return 3+random(4);     
}


