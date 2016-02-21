//sanban, 无敌三板斧
//created 6-10-97 pickle
 
#include <ansi.h>
 
inherit SSERVER;

int perform(object me, object target)
{
  string msg,str,targetrude;
  int success,hurt,diff,damage;
  int myexp=(int)me->query("combat_exp")/5000;
  int mylev=(int)me->query_skill("axe");
  int mystr=(int)me->query("str")+(int)(me->query_skill("unarmed")/10-2);
  int mykar=(int)me->query_kar();
  int targetlev, targetstr,targetkar,targetexp,targeteffkee;
  string *hitone = ({
    "$n试图侧身避开，但为时已晚。大斧劈在肩上，留下一道深可见骨的伤口！\n",
    "$n高举手中兵刃试图架开，但挡不住$N的来势，被震得吐出一口鲜血！\n",
    "$n以攻为守，但去势不够凌厉。虽逼得$N回斧自护，但还是在$n肩膀带出一道伤口。\n",
  });
  string *missone = ({
    "$n轻轻一闪，大斧带着一阵劲风从身边斩下，但没伤到$n分毫。\n",
    "$n高举手中兵刃奋力一架，只听「当」的一声巨响，$N巨斧已被弹开！\n",
    "$n不顾大斧来势，反而向$N疾攻，逼得$N不得不回斧自保，这一势「开瓜」就此落空。\n",
  });
  string *hittwo = ({
    "$n似乎没有觉出危险，顺手一挡。待到发觉来势之疾，为时已晚。脸上已多了一条数寸长的伤口！\n",
    "$n没想道$N攻势如此之快，急忙低头闪避，但无法躲开，被刀刃划得皮开肉绽！\n",
    "$n攻势已然发出，来不及回防，脸上被割掉一片皮，显然伤得不轻！\n",
  });
  string *misstwo = ({
    "$n脑袋微微一侧，避过了$N的攻势。\n",
    "$n似乎早已料到这一招，顺势在斧杆上一推，避了开去。\n",
    "眼看这招要把$n脑袋戳个对穿，突然间$n使个铁板桥，护手刀落了个空。\n",
  });
  string *hitthree = ({
    "$n似乎已被这三斧连环的威势吓破了胆，懒懒散散地一歪，被大斧横劈在肩头。\n",
    "$n看准来势，以手中兵器架去，但已力不从心，被斧头震得虎口出血，显然内伤不轻！\n",
    "$n眼见来势凌厉，企图低头避过，但不料大斧随着下劈，从$n背上割下一大片皮肉！\n",
  });
  string *missthree = ({
    "$n似乎早已熟知大斧来路，斧未到，人已先轻飘飘地避开了。\n",
    "$n眼见躲不过来招，急忙在地上一滚。虽然避得狼狈，但丝毫没有受伤。\n",
    "$n不顾自身危险，中宫直进，向$N攻去，果然将来招化解了。\n",
  });
  string *hit=({
    RED"$N道：也叫你尝尝这无敌三板斧的厉害！\n"NOR,
    RED"这无敌三板斧一气呵成，$n被攻了个措手不及，伤势甚为可怕！\n"NOR,
    RED"$N狂笑道：就凭你这点本事，也来跟我斗？\n"NOR,
  });
  string *miss;
  
  if( !target ) target = offensive_target(me);
  if(me->query("family/family_name")!="将军府")
                return notify_fail("你不是将军府弟子，不能使用这项技能！\n");
  if( !target
     ||      !target->is_character()
     ||      !me->is_fighting(target) )
    return notify_fail("无敌三板斧不是练着好看的，只能对战斗对手施用。\n");
  targetrude=RANK_D->query_self_rude(target);
  targetexp=(int)target->query("combat_exp")/5000;
  targetlev=(int)target->query_skill("parry");
  targetstr=(int)target->query("str")+(int)(target->query_skill("unarmed")/10-2);
  targetkar=(int)target->query_kar();
  miss=({
    BLU"$n哈哈大笑道："+targetrude+"听说这无敌三板斧有多少威力，现在一看，也不过如此嘛！\n"NOR,
    BLU"$n长笑一声，对$N不屑地说道：就这点本事，"+targetrude+"还没放在眼里！\n"NOR,
    BLU"$n仰天大笑道：还有什么本事，尽管拿出来吧！\n"NOR,
  });
  if((string)me->query_skill_mapped("force")!="lengquan-force")
    return notify_fail("无敌三板斧必须以冷泉神功为底子。\n");
  if(me->query_skill("lengquan-force",1) < 100)
    return notify_fail("你的内功底子不足，无法运斧如风，施展不出无敌三板斧。\n");
  if(me->query_skill("sanban-axe",1)<100)
    return notify_fail("你对宣花三斧不够熟悉，无法一气呵成地使出！\n");
  if(me->query("max_force") < 1000 || me->query("force")<500)
    return notify_fail("你的内力不足，难以随意挥动一柄大斧。\n");
  msg = CYN "$N一声暴喝：开瓜！剔牙！掏耳朵！三招一气呵成！\n\n只见一道青影划过，大斧直劈$n顶门！\n" NOR;
  if( random(mylev+targetlev+mystr*3+targetstr*3) > (targetlev+targetstr*3))
    {
      msg += hitone[random(sizeof(hitone))];
      success+=1;
      if(random(mykar+targetkar)>targetkar) hurt+=1;
      damage=15+random(mykar/3);
    }
  else msg+=missone[random(sizeof(missone))];
  msg+=CYN"\n$N大斧已经带过，顺势以斧尾护手尖刀疾挑$n面门！\n"NOR;
  if( random(myexp+targetexp+mylev+targetlev) > (targetexp+targetlev))
    {
      msg += hittwo[random(sizeof(hittwo))];
      success+=1;
      if(random(mykar+targetkar)>targetkar) hurt+=1;
      damage+=15+random(mykar/3);
    }
  else msg+=misstwo[random(sizeof(misstwo))];
  msg+=CYN"\n$N迅疾无伦地翻转斧头，大斧向$n脑袋横劈过去！\n"NOR;
  if(random(myexp+targetexp+mykar*10+targetkar*10)>(targetexp+targetkar))
    {
      msg+=hitthree[random(sizeof(hitthree))];
      success+=1;
      if(random(mykar+targetkar)>targetkar) hurt+=1;
      damage+=15+random(mykar/3);
    }
  else msg+=missthree[random(sizeof(missthree))];
  diff=3-success;
  if (diff<0) diff = 0;
  if (success) hurt=damage*hurt/success;
  else hurt=0;
  me->add("force", -(10*success+20*diff));
  targeteffkee=(int)target->query("eff_sen");
  target->receive_wound("kee", targeteffkee*hurt/300);
  target->receive_damage("kee", target->query("kee")*(damage-hurt)/100);
    if (target->query("eff_kee")<0 || (!living(target) && target->query("kee")<0))
{str=target->name()+HIM"被"+me->name()+"用将军府"NOR+HIR"「无敌三板斧」"+HIM"砍死了，据说"+target->name()+"尸体被劈的血肉模糊！";
message("channel:rumor",HIM"【空穴来风】某人："+str+"\n"NOR,users());
}
  if(success)
    {
      me->start_busy(1+random(4-(mykar+5)/10));
      msg+=hit[random(sizeof(hit))];
    }
  else
    {
      me->start_busy(random(4-(mykar+5)/10));
      msg+=miss[random(sizeof(miss))];
    }
  message_vision(msg, me, target);
  return 1;
}
