// combatd.c

#pragma optimize

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#include "/cmds/std/valid_kill.h"


inherit F_DBASE;

int victim_lose(object killer,object victim,string killerid);
void victim_penalty(object victim);
int nk_gain(object killer, object victim);
string chinese_daoxing(int gain);

int check_family(string fam);

//this mapping indicates whether this family class is
//xian or yao.
mapping family=(["方寸山三星洞":1,
                 "南海普陀山":1,
                 "将军府":1,
                 "五庄观":1,
                 "阎罗地府":0,
                 "月宫":0,
                 "东海龙宫":0,
         "龙宫":0,
                 "大雪山":-1,
                 "翠云山芭蕉洞":-1,
                 "陷空山无底洞":-1,
                 "乱石山碧波潭":-1, 
         "火云洞":-1,
]);

string *guard_msg = ({
    CYN "$N注视着$n的行动，企图寻找机会出手。\n" NOR,
    CYN "$N正盯着$n的一举一动，随时准备发动攻势。\n" NOR,
    CYN "$N缓缓地移动脚步，想要找出$n的破绽。\n" NOR,
    CYN "$N目不转睛地盯着$n的动作，寻找进攻的最佳时机。\n" NOR,
    CYN "$N慢慢地移动着脚步，伺机出手。\n" NOR,
});

string *catch_hunt_msg = ({
    HIW "$N和$n仇人相见份外眼红，立刻打了起来！\n" NOR,
    HIW "$N对着$n大喝：「可恶，又是你！」\n" NOR,
    HIW "$N和$n一碰面，二话不说就打了起来！\n" NOR,
    HIW "$N一眼瞥见$n，「哼」的一声冲了过来！\n" NOR,
    HIW "$N一见到$n，愣了一愣，大叫：「我宰了你！」\n" NOR,
    HIW "$N喝道：「$n，我们的帐还没算完，看招！」\n" NOR,
    HIW "$N喝道：「$n，看招！」\n" NOR,});

string *winner_msg = ({
    CYN "\n$N哈哈大笑，说道：承让了！\n\n" NOR,
    CYN "\n$N双手一拱，笑着说道：承让！\n\n" NOR,
    CYN "\n$N胜了这招，向后跃开三尺，笑道：承让！\n\n" NOR,
    CYN "\n$n脸色微变，说道：佩服，佩服！\n\n" NOR,
    CYN "\n$n向后退了几步，说道：这场比试算我输了，佩服，佩服！\n\n" NOR,
    CYN "\n$n向后一纵，躬身做揖说道：阁下武艺不凡，果然高明！\n\n" NOR,
});

void create()
{
    seteuid(getuid());
    set("name", "战斗精灵");
    set("id", "combatd");
}

string damage_msg(int damage, string type)
{
    string str;

//  return "造成 " + damage + " 点" + type + "。\n";

    if( damage == 0 ) return "结果没有造成任何伤害。\n";

    switch( type ) {
    case "擦伤":
    case "抓伤":
    case "割伤":
        if( damage < 10 ) return "结果只是轻轻地划破$p的皮肉。\n";
        else if( damage < 20 ) return "结果在$p$l划出一道细长的血痕。\n";
        else if( damage < 40 ) return "结果「嗤」地一声划出一道伤口！\n";
        else if( damage < 80 ) return "结果「嗤」地一声划出一道血淋淋的伤口！\n";
        else if( damage < 160 ) return "结果「嗤」地一声划出一道又长又深的伤口，溅得$N满脸鲜血！\n";
        else return "结果只听见$n一声惨嚎，$p的$l被划出一道深及见骨的可怕伤口！\n";
        break;
    case "砍伤":
    case "劈伤":
        if( damage < 10 ) return "结果只是在$n的皮肉上碰了碰，跟蚊子叮差不多。\n";
        else if( damage < 20 ) return "结果在$n$l砍出一道细长的血痕。\n";
        else if( damage < 40 ) return "结果「噗嗤」一声劈出一道血淋淋的伤口！\n";
        else if( damage < 80 ) return "结果只听「噗」地一声，$n的$l被劈得血如泉涌，痛得$p咬牙切齿！\n";
        else if( damage < 160 ) return "结果「噗」地一声砍出一道又长又深的伤口，溅得$N满脸鲜血！\n";
        else return "结果只听见$n一声惨嚎，$p的$l被劈开一道深及见骨的可怕伤口！\n";
        break;
    case "枪伤":
    case "刺伤":
        if( damage < 10 ) return "结果只是轻轻地刺破$p的皮肉。\n";
        else if( damage < 20 ) return "结果在$p$l刺出一个创口。\n";
        else if( damage < 40 ) return "结果「噗」地一声刺入了$n$l寸许！\n";
        else if( damage < 80 ) return "结果「噗」地一声刺进$n的$l，使$p不由自主地退了步！\n";
        else if( damage < 160 ) return "结果「噗嗤」地一声，$w已在$p$l刺出一个血肉模糊的血窟窿！\n";
        else return "结果只听见$n一声惨嚎，$w已在$p的$l对穿而出，鲜血溅得满地！\n";
        break;
    case "筑伤":
        if( damage < 10 ) return "结果只是轻轻地一触，在$n的皮肤上留下一点白痕。\n";
        else if( damage < 20 ) return "结果在$p的$l留下几道血痕。\n";
        else if( damage < 40 ) return "结果一下子筑中，$n的$l顿时出现几个血孔！\n";
        else if( damage < 80 ) return "结果一下子筑中，$n立刻血流如注！\n";
        else if( damage < 120 ) return "结果「哧」地一声，$n顿时鲜血飞溅！\n";
        else if( damage < 160 ) return "结果这一下「哧」地一声，$n被筑得浑身是血！\n";
        else return "结果「哧」重重地砸中，$n被筑得千疮白孔，血肉四处横飞！\n";
        break;
    case "掌伤":
    case "拳伤":
    case "瘀伤":
        if( damage < 10 ) return "结果只是轻轻地碰到，比拍苍蝇稍微重了点。\n";
        else if( damage < 20 ) return "结果在$p的$l造成一处瘀青。\n";
        else if( damage < 40 ) return "结果一击命中，$n的$l登时肿了一块老高！\n";
        else if( damage < 80 ) return "结果一击命中，$n闷哼了一声显然吃了不小的亏！\n";
        else if( damage < 120 ) return "结果「砰」地一声，$n退了两步！\n";
        else if( damage < 160 ) return "结果这一下「砰」地一声打得$n连退了好几步，差一点摔倒！\n";
        else if( damage < 240 ) return "结果重重地击中，$n「哇」地一声吐出一口鲜血！\n";
        else return "结果只听见「砰」地一声巨响，$n像一捆稻草般飞了出去！\n";
        break;
    case "撞伤":
    case "砸伤":
        if( damage < 10 ) return "结果只是轻轻地碰到，等于给$n搔了一下痒。\n";
        else if( damage < 20 ) return "结果在$p的$l砸出一个小臌包。\n";
        else if( damage < 40 ) return "结果砸个正着，$n的$l登时肿了一块老高！\n";
        else if( damage < 80 ) return "结果砸个正着，$n闷哼一声显然吃了不小的亏！\n";
        else if( damage < 120 ) return "结果「砰」地一声，$n疼得连腰都弯了！\n";
        else if( damage < 160 ) return "结果这一下「轰」地一声砸得$n眼冒金星，差一点摔倒！\n";
        else if( damage < 240 ) return "结果重重地砸中，$n眼前一黑，「哇」地一声吐出一口鲜血！\n";
        else return "结果只听见「轰」地一声巨响，$n被砸得血肉模糊，惨不忍睹！\n";
        break;
    case "震伤":
    case "内伤":
        if( damage < 20 ) return "结果在$n身上一触即逝，等于给$n搔了一下痒。\n";
        else if( damage < 40 ) return "结果$n晃了一晃，吃了点小亏。\n";
        else if( damage < 80 ) return "结果$n气息一窒，显然有点呼吸不畅！\n";
        else if( damage < 120 ) return "结果$n体内一阵剧痛，看起来内伤不轻！\n";
        else if( damage < 160 ) return "结果「嗡」地一声$n只觉得眼前一黑，双耳轰鸣不止！\n";
        else return "结果只听见「嗡」地一声巨响，$n「哇」地一声吐出一口鲜血，五脏六腑都错了位！\n";
        break;
        case "鞭伤":
        case "抽伤":
        if( damage < 10 ) return "结果只是在$n的皮肉上碰了碰，跟蚊子叮差不多。\n";
        else if( damage < 20 ) return "结果在$n$l抽出一道轻微的紫痕。\n";
        else if( damage < 40 ) return "结果「啪」地一声在$n$l抽出一道长长的血痕！\n";
        else if( damage < 80 ) return "结果只听「啪」地一声，$n的$l被抽得皮开肉绽，痛得$p咬牙切齿！\n";
        else if( damage < 160 ) return "结果「啪」地一声爆响！这一下好厉害，只抽得$n皮开肉绽，血花飞溅！\n";
        else return "结果只听见$n一声惨嚎，$w重重地抽上了$p的$l，$n顿时血肉横飞，十命断了九条！\n";
        break;
    default:
        if( !type ) type = "伤害";
        if( damage < 10 ) str =  "结果只是勉强造成一处轻微";
        else if( damage < 20 ) str = "结果造成轻微的";
        else if( damage < 30 ) str = "结果造成一处";
        else if( damage < 50 ) str = "结果造成一处严重";
        else if( damage < 80 ) str = "结果造成颇为严重的";
        else if( damage < 120 ) str = "结果造成相当严重的";
        else if( damage < 170 ) str = "结果造成十分严重的";
        else if( damage < 230 ) str = "结果造成极其严重的";
        else str =  "结果造成非常可怕的严重";
        return str + type + "！\n";
    }
}

string eff_status_msg(int ratio)
{
    if( ratio==100 ) return HIG "看起来气血充盈，并没有受伤。" NOR;
    if( ratio > 95 ) return HIG "似乎受了点轻伤，不过光从外表看不大出来。" NOR;
    if( ratio > 90 ) return HIY "看起来可能受了点轻伤。" NOR;
    if( ratio > 80 ) return HIY "受了几处伤，不过似乎并不碍事。" NOR;
    if( ratio > 60 ) return HIY "受伤不轻，看起来状况并不太好。" NOR;
    if( ratio > 40 ) return HIR "气息粗重，动作开始散乱，看来所受的伤着实不轻。" NOR;
    if( ratio > 30 ) return HIR "已经伤痕累累，正在勉力支撑着不倒下去。" NOR;
    if( ratio > 20 ) return HIR "受了相当重的伤，只怕会有生命危险。" NOR;
    if( ratio > 10 ) return RED "伤重之下已经难以支撑，眼看就要倒在地上。" NOR;
    if( ratio > 5  ) return RED "受伤过重，已经奄奄一息，命在旦夕了。" NOR;
    return RED "受伤过重，已经有如风中残烛，随时都可能断气。" NOR;
}

string status_msg(int ratio)
{
    if( ratio==100 ) return HIG "看起来充满活力，一点也不累。" NOR;
    if( ratio > 95 ) return HIG "似乎有些疲惫，但是仍然十分有活力。" NOR;
    if( ratio > 90 ) return HIY "看起来可能有些累了。" NOR;
    if( ratio > 80 ) return HIY "动作似乎开始有点不太灵光，但是仍然有条不紊。" NOR;
    if( ratio > 60 ) return HIY "气喘嘘嘘，看起来状况并不太好。" NOR;
    if( ratio > 40 ) return HIR "似乎十分疲惫，看来需要好好休息了。" NOR;
    if( ratio > 30 ) return HIR "已经一副头重脚轻的模样，正在勉力支撑着不倒下去。" NOR;
    if( ratio > 20 ) return HIR "看起来已经力不从心了。" NOR;
    if( ratio > 10 ) return RED "摇头晃脑、歪歪斜斜地站都站不稳，眼看就要倒在地上。" NOR;
    return RED "已经陷入半昏迷状态，随时都可能摔倒晕去。" NOR;
}

//report_shen messages
string sen_status_msg(int ratio)
{
    if( ratio==100 ) return HIG "看起来头脑清醒，一点也不迷糊。" NOR;
    if( ratio > 90 ) return HIG "拍了拍自己的脑袋，似乎有点不太得劲。" NOR;
    if( ratio > 80 ) return HIY "看起来有些迷糊了。" NOR;
    if( ratio > 60 ) return HIY "的确有点迷糊了，但还辨得出东西南北。" NOR;
    if( ratio > 40 ) return HIR "两眼发直，口角流涎，神智开始混乱。" NOR;
    if( ratio > 20 ) return HIR "迷迷糊糊，摇摇晃晃，已经辨不出东西南北了。" NOR;
    if( ratio > 10 ) return RED "神智已经处在极度混乱中。" NOR;
    return RED "心智已经完全迷失，随时都有可能背过气去。" NOR;
}

varargs void report_status(object ob, int effective)
{
    if( effective ) 
        message_vision( "( $N" + eff_status_msg(
                   (int)ob->query("eff_kee") * 100 /(1+(int)ob->query("max_kee")) ) 
                   + " )\n", ob);
    else
        message_vision( "( $N" + status_msg(
                   (int)ob->query("kee") * 100/(1+(int)ob->query("max_kee")) ) 
                   + " )\n", ob);
}

varargs void report_sen_status(object ob, int effective)
{
    
    message_vision( "( $N" + sen_status_msg(
        (int)ob->query("sen") * 100 /(1+(int)ob->query("max_sen")) ) 
        + " )\n", ob);
}

// This function calculates the combined skill/combat_exp power of a certain
// skill. This value is used for A/(A+B) probability use.
varargs int skill_power(object ob, string skill, int usage)
{
    int status, level, power;

    if( !living(ob) ) return 0;

    level = ob->query_skill(skill);

    switch(usage) {
        case SKILL_USAGE_ATTACK:
            level = ob->eff_skill_level(level, SKILL_USAGE_ATTACK);
            level += ob->query_temp("apply/attack");
            break;
        case SKILL_USAGE_DEFENSE:
            level = ob->eff_skill_level(level, SKILL_USAGE_DEFENSE);
            level += ob->query_temp("apply/defense");
            break;
    }

    if( !level ) return (int)ob->query("combat_exp") / 2;

    power = (level*level*level) / 3;
    if( (status = ob->query("max_sen")) > 0 )  {
        if ( power > 100000 )
           power = power / status * (int)ob->query("sen");
        else
           power = power * (int)ob->query("sen") / status;
    }

    power +=  ob->query("combat_exp");

    return power;
}

// do_attack()
//
// Perform an attack action. This function is called by fight() or as an
// interface for some special utilize in quests.
//add by bear
varargs int do1_attack(object me, object victim,object who)     //功城的执行
{
int myda,vda;
int one,two,three;
int ap,dp;
one=me->query("soilder");
two=victim->query("soilder");
three=victim->query("defendance");
message_vision("$N将手中长刀一挥。兵将蚁聚，涌至城边，一边架起云梯攀越城墙，一边掘土而进。\n",me);
message_vision("$N只见城墙上万箭齐飞，擂石并发，守得是雷打不动，水泼不进。\n",me);
ap=one*me->query("train_level");
dp=two*(victim->query("train_level")+three);
if((ap<=0)&&(dp>0))
{
message("vision",HIY+"【武林飞檄】:"+NOR+HIC+me->query("name")+"对"+
victim->query("short")+"的进攻无功而返。"+who->query("name")+"守卫胜利.\n"NOR,users());
tell_object(who,"你保卫了城市，得到了一年的道行奖励。\n");
who->add("combat_exp",1000);
me->set("soilder",0);
me->set("train_level",0);
me->remove_enemy(victim);
me->delete("attacking");	
victim->delete("receive_attack");
victim->save();
return 1;
}
if((ap>0)&&(dp<=0) )
{
message("vision",HIY+"【武林飞檄】:"+NOR+HIC+me->query("name")+"攻占了"+
victim->query("short")+" ,"+who->query("name")+"守卫失利.\n"NOR,users());
victim->set("owner",me->query("id"));
victim->set("soilder",0);
victim->set("train_level",0);
me->remove_enemy(victim);
me->delete("attacking");	
victim->delete("receive_attack");
victim->save();
return 1;
}
if(ap < dp )
{
message_vision("$N的守势当真牢靠，在一阵激烈的肉搏之后，$n的攻势缓了下来。\n",who,me);
myda=(dp-ap)/1000;
if(myda<=0) myda=-1*myda+1;
tell_object(me,"敌人拼命抵抗，你折损了:"+chinese_number(myda)+"名人马。\n");
me->add("soilder",-myda);
tell_object(who,"敌人拼命进攻，你折损了:"+chinese_number(myda/2)+"名人马。\n");
victim->add("soilder",-myda/5);
}else
if(ap < 5*dp)
{
message_vision("$N的守势当真顽强，在一阵激烈的肉搏之后，$n还是拿不下来。\n",who,me);
myda=(ap-dp)*dp/(ap*1000);
vda=(ap-dp)*ap/(dp*1000);
if(vda<=0) vda=-1*vda+1;
if(myda<=0) myda=-1*myda+1;
tell_object(me,"敌人拼命抵抗，你折损了:"+chinese_number(myda)+"名人马。\n");
me->add("soilder",-myda);
tell_object(who,"敌人拼命进攻，你折损了:"+chinese_number(vda)+"名人马。\n");
victim->add("soilder",-vda);
victim->add("defendance",-1);
if(victim->query("defendance")<0) victim->set("defendance",0);
}else 
{
message_vision("$N的守势虽然顽强，在一阵激烈的肉搏之后，$n还是渐渐占了优势。\n",who,me);
myda=(ap-dp)*dp/(ap*2000);
vda=(ap-dp)*ap/(dp*500);
if(vda<=0) vda=-1*vda+1;
if(myda<=0) myda=-1*myda+1;

tell_object(me,"敌人抵抗渐弱，你折损了:"+chinese_number(myda)+"名人马。\n");
me->add("soilder",-myda);
tell_object(who,"敌人拼命进攻，你折损了:"+chinese_number(vda)+"名人马。\n");
victim->add("soilder",-vda);
victim->add("defendance",-2);
if(victim->query("defendance")<0) victim->set("defendance",0);
}
}
//攻城完毕
varargs int do_attack(object me, object victim, object weapon, int attack_type)
{
    mapping my, your, action, victim_action;
    string limb, *limbs, result,fail_hit_msg,hit_ob_msg;
    string attack_skill, force_skill, martial_skill, dodge_skill, parry_skill;
    mixed foo;
    int ap, dp, pp, afp, vfp;   //afp: attacker->force power, vfp: victim->force power
    int damage, damage_bonus, defense_factor,force_adj;
    int wounded = 0;
    //int cost;
    int mod_val;

    my = me->query_entire_dbase();
    your = victim->query_entire_dbase();

    //
    // (1) Find out what action the offenser will take.
    //
    action = me->query("actions");
    if( !mapp(action) ) {
        me->reset_action();
        action = me->query("actions");
        if( !mapp(action) ) {
            CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("%s(%s): bad action = %O",
                    me->name(1), me->query("id"), me->query("actions", 1)));
            return 0;
        }
    }
    if (action["name"])
        me->set_temp("action_name",action["name"]);
    result = "\n" + action["action"] + "！\n";
    
    //取得me用什么兵器的数据   
       if( objectp(weapon) )   {
            if( weapon->query("use_apply_skill") )
                attack_skill = weapon->query("apply/skill_type");
            else
                attack_skill = weapon->query("skill_type");
        }
    else                    attack_skill = "unarmed";

    limbs = victim->query("limbs");
    limb = limbs[random(sizeof(limbs))];
    
       //(2) 加上特殊内功的防御能力 added by yeahsi
       if ( victim->query_temp("jldl") && living(victim) )       //如果敌人运用了jldl,而且不是晕的                          
             { 
                afp = skill_power(me, "force", SKILL_USAGE_ATTACK);
            if( afp < 1) afp = 1;
            vfp = skill_power(victim, "force", SKILL_USAGE_DEFENSE);
            if( vfp < 1 ) vfp = 1;
            mod_val = 0;
            mod_val -= random(25);
            if (!victim->query_temp("weapon")) mod_val += 10;
            if( vfp > 1000000 )     mod_val = vfp / 100 * (100 + mod_val);
                     else   mod_val = (100 + mod_val) * vfp / 100;
            if( mod_val < 1 ) mod_val = 1;
            force_adj=random(afp + vfp);
         }
            else {force_adj=1;mod_val=1;}
    

    //
    // (3) Fight!
    //     Give us a chance of AP/(AP+DP) to "hit" our opponent. Since both
    //     AP and DP are greater than zero, so we always have chance to hit
    //     or be hit.
    //
   
   
      
           
            if ( force_adj < mod_val )
            {foo = "/daemon/class/puti/wuxiangforce/jldl"->jldl_result(victim, me, mod_val, force_adj,action);
                 result += foo;
                 damage = RESULT_FORCE;
   
    

} else { //
        //  Prepare AP, DP for checking if hit.
       //
    
	

    ap = skill_power(me, attack_skill, SKILL_USAGE_ATTACK);
    if( ap < 1) ap = 1;

    dp = skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
    // mon 8/3/98
    if(living(victim)) 
          dodge_skill = victim->query_skill_mapped("dodge");
    else
        dodge_skill = 0;
    mod_val = 0;
    if( dodge_skill )  {
           victim_action = SKILL_D(dodge_skill)->query_action();
       if( victim_action && victim_action["dodge_power"] )
          mod_val = victim_action["dodge_power"];
    }
    if( victim->is_busy() ) dp /= 3;
    if( dp < 1 ) dp = 1;

    if( action["dodge"] )  mod_val += action["dodge"];
    if( dp > 1000000 )
       mod_val = dp / 100 * (100 + mod_val);
    else 
       mod_val = (100 + mod_val) * dp / 100;
    if( mod_val < 1 ) mod_val = 1;
	
	if( random(ap + dp) < mod_val ) {       // Does the victim dodge this hit?

        if( !dodge_skill ) {
           dodge_skill = "dodge"; 
           result += SKILL_D(dodge_skill)->query_dodge_msg(limb);
        }
        else   {
           if( victim_action && victim_action["dodge_action"] )
              result += victim_action["dodge_action"];
        else
              result += SKILL_D(dodge_skill)->query_dodge_msg(limb);
        }

        if( dp < ap && (!userp(victim) || !userp(me)) 
        &&      random(sizeof(victim->query_enemy())) < 4
        &&  random(your["sen"]*100/your["max_sen"] + your["int"]*your["cps"]) > 150 ) {
            your["combat_exp"] += 1;
            victim->improve_skill("dodge", 1);
        }

        // This is for NPC only. NPC have chance to get exp when fail to hit.
        if( (ap < dp) && !userp(me) ) {
            if( random(my["int"]) > 15 ) my["combat_exp"] += 1;
            me->improve_skill(attack_skill, random(my["int"]));
        }
        damage = RESULT_DODGE;

        

        } else {//
        //  (4) Check if the victim can parry this attack.
        //
        if( victim->query_temp("weapon") ) {
            pp = skill_power(victim, "parry", SKILL_USAGE_DEFENSE);
            if( !weapon ) pp *= 2;
            parry_skill = victim->query_skill_mapped("parry");
        } else {
            if( weapon ) pp = 0;
            else pp = skill_power(victim, "unarmed", SKILL_USAGE_DEFENSE);
            parry_skill = victim->query_skill_mapped("unarmed");
        }

        if( victim->is_busy() ) pp /= 3;
        if( pp < 1 ) pp = 1;
        mod_val = 0;
        if( action["parry"] )       mod_val = action["parry"];
        if( pp > 1000000 )
           mod_val = pp / 100 * (100 + mod_val);
        else
           mod_val = (100 + mod_val) * pp / 100;
        if(mod_val < 1)  mod_val = 1;

        if( random(ap + pp)< mod_val ) {

            //parry_skill = victim->query_skill_mapped("parry");
            if( !parry_skill ) parry_skill = "parry";
            // change to SKILL_D(parry_skill) after added parry msg to those
            // martial arts that can parry.
            // because of number of local variable limit, here use
            // dodge_skill
            dodge_skill = SKILL_D(parry_skill)->query_parry_msg(weapon);
            if( dodge_skill )       result += dodge_skill;
            else
                result += SKILL_D("parry")->query_parry_msg(weapon);

            if( pp < ap && (!userp(victim) || !userp(me)) 
            &&      random(sizeof(victim->query_enemy())) < 4
            &&  random(your["sen"]*100/your["max_sen"] + your["int"]*your["cps"]) > 150 ) {
                your["combat_exp"] += 1;
                victim->improve_skill("parry", 1);
            }
            damage = RESULT_PARRY;
                } else{

            //
            //  (5) We hit the victim and the victim failed to parry
            //

            damage = me->query_temp("apply/damage");
            damage = (damage + random(damage)) / 2;
            if( action["damage"] )
                damage += action["damage"] * damage / 100;

            damage_bonus = me->query_str();

            // Let force skill take effect.
            if( my["force_factor"] && (my["force"] > my["force_factor"]) ) {
                if( force_skill = me->query_skill_mapped("force") ) {
                    foo = SKILL_D(force_skill)->hit_ob(me, victim, damage_bonus, my["force_factor"]);
                    if( stringp(foo) ) result += foo;
                    else if( intp(foo) ) damage_bonus += foo;
                }
            }

            if( action["force"] )
                damage_bonus += action["force"] * damage_bonus / 100;

            if( martial_skill = me->query_skill_mapped(attack_skill) ) {
                foo = SKILL_D(martial_skill)->hit_ob(me, victim, damage_bonus);
                if( stringp(foo) ) result += foo;
                else if(intp(foo) ) damage_bonus += foo;
            }

            // Let weapon or monster have their special damage.
            if( weapon ) {
                foo = weapon->hit_ob(me, victim, damage_bonus);
                if( stringp(foo) ) result += foo;
                else if(intp(foo) ) damage_bonus += foo;
            } else {
                foo = me->hit_ob(me, victim, damage_bonus);
                if( stringp(foo) ) result += foo;
                else if(intp(foo) ) damage_bonus += foo * 3 / 4;
            }

            if( damage_bonus > 0 )
                damage += (damage_bonus + random(damage_bonus))/2;
            if( damage < 0 ) damage = 0;

            // Let combat exp take effect
            defense_factor = your["combat_exp"];
            while( random(defense_factor) > my["combat_exp"] ) {
                damage -= damage / 3;
                defense_factor /= 2;
            }

            //
            //  (6) Inflict the damage.
            //

            damage = victim->receive_damage("kee", damage, me );

            if( (me->is_killing(victim) || weapon)
            && random(damage) > (int)victim->query_temp("apply/armor") ) {
                // We are sure that damage is greater than victim's armor here.
                victim->receive_wound("kee",
                    damage - (int)victim->query_temp("apply/armor"), me);
                wounded = 1;
            }
                       
                        if (me->query_temp("ldlh")) result = "\n" + action["action"] + "！\n";
            result += damage_msg(damage, action["damage_type"]);

            //
            //  (7) Give experience
            //

            if( !userp(me) || !userp(victim) ) {
                if( (ap < dp)
                &&  (random(my["sen"]*100/my["max_sen"] + my["int"]*my["cps"]) > 150) ) {
                    my["combat_exp"] += 1;
                    if( my["potential"] - my["learned_points"] < 100 )
                        my["potential"] += 1;
                    me->improve_skill(attack_skill, 1);
                }
                if( random(your["max_kee"] + your["kee"]) < damage ) {
                    your["combat_exp"] += 1;
                    if( your["potential"] - your["learned_points"] < 100 )
                        your["potential"] += 1;
                }
            }
        }
    } }

    result = replace_string( result, "$l", limb );
    if( objectp(weapon) )
        result = replace_string( result, "$w", weapon->name() );
    else if( stringp(action["weapon"]) )
        result = replace_string( result, "$w", action["weapon"] );
    if( objectp(victim->query_temp("weapon")) )
        result = replace_string( result, "$W", 
          victim->query_temp("weapon")->name() );

    if ( (damage != RESULT_DODGE) && (damage != RESULT_PARRY) )
		{message_vision(result, me, victim );
		 if ( damage == RESULT_FORCE && me->query("eff_kee")<0 )
		      {CHANNEL_D->do_channel(victim, "rumor",me->name()+"中了"+victim->name()+"的拨转招式之法，自己把自己打死了。");
	               victim->delete_temp("last_channel_msg");
	              }
	        }
	else
		{if ( ((string)me->query("env/brief_message") != "YES" 
		  && (string)victim->query("env/brief_message") != "YES") || me->query_temp("ldlh") ) 
			message_vision(result, me, victim );
                if( martial_skill = me->query_skill_mapped(attack_skill) )
		{fail_hit_msg=SKILL_D(martial_skill)->fail_hit(me, victim);
		 if (stringp(fail_hit_msg)) message_vision(fail_hit_msg,me,victim);
		}}

    if( wizardp(me) && (string)me->query("env/combat")=="verbose" ) {
        if( damage > 0 )
            tell_object(me, sprintf( GRN "AP：%d，DP：%d，PP：%d，Mod：%d，伤害力：%d\n" NOR,
                ap/100, dp/100, pp/100, mod_val/100, damage));
        else
            tell_object(me, sprintf( GRN "AP：%d，DP：%d，PP：%d，Mod：%d\n" NOR,
                ap/100, dp/100, pp/100, mod_val/100));
    }
    if( wizardp(victim) && (string)victim->query("env/combat")=="verbose" ) {
        if( damage > 0 )
            tell_object(victim, sprintf( GRN "AP：%d，DP：%d，PP：%d，Mod：%d，伤害力：%d\n" NOR,
                ap/100, dp/100, pp/100, mod_val/100, damage));
        else
            tell_object(victim, sprintf( GRN "AP：%d，DP：%d，PP：%d，Mod：%d\n" NOR,
                ap/100, dp/100, pp/100, mod_val/100));
    }

    if( damage > 0 ) {
        report_status(victim, wounded);
        if( martial_skill = me->query_skill_mapped(attack_skill) )
        {hit_ob_msg=SKILL_D(martial_skill)->hit_ob_msg(me, victim);
         if (stringp(hit_ob_msg)) message_vision(hit_ob_msg,me,victim);
        }
        
    if ( me->query_temp("zxzx") == 1 )
         {"/daemon/class/yaomo/wudidong/qixiu-jian/zxzx"->zxzx_effect(me,victim);}
        
        if( victim->is_busy() ) victim->interrupt_me(me);
        if( (!me->is_killing(your["id"])) && (!victim->is_killing(my["id"])) ) {
          // fight until one side's kee is < 50%
          if( victim->query("kee") < victim->query("max_kee") * 50 / 100)  {
             me->remove_enemy(victim);
             victim->remove_enemy(me);
             message_vision( winner_msg[random(sizeof(winner_msg))], me, victim);
          }
        }
    }

    if( functionp(action["post_action"]) )
        evaluate( action["post_action"], me, victim, weapon, damage);

    if( damage > 0 && attack_type != TYPE_QUICK &&
    me->query_temp("perf_quick") && me->is_fighting(victim) )   {
        if( me->query_temp("weapon") &&
        me->query_temp("perf_quick/"+me->query_temp("weapon")->query("skill_type")) )  {
           if( me->query_temp("perf_quick/msg") )
               message_vision(CYN + me->query_temp("perf_quick/msg") +NOR, me, victim);
           else
               message_vision(CYN + "$N得势不饶人，对$n展开连续攻击。"+NOR, me, victim);
           do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
           return 1;
        }
    }

    // See if the victim can make a riposte.
    if( attack_type==TYPE_REGULAR
    &&  damage < 1
    &&  victim->query_temp("guarding") ) {
        victim->set_temp("guarding", 0);
        if( random(my["cps"]) < 5 ) {
            message_vision("$N一击不中，露出了破绽！\n", me);
            do_attack(victim, me, victim->query_temp("weapon"), TYPE_QUICK);
        } else {
            message_vision("$N见$n攻击失误，趁机发动攻击！\n", victim, me);
            do_attack(victim, me, victim->query_temp("weapon"), TYPE_RIPOSTE);
        }
    }
       return damage;
}

//  fight()
//
//  This is called in the attack() defined in F_ATTACK, which handles fighting
//  in the heart_beat() of all livings. Be sure to optimize it carefully.
//
void fight(object me, object victim)
{
    object ob;

    if( !living(me) ) return;
    if( me->query_temp("netdead") )  return;
    if( victim->query_temp("netdead") )   {
        if( member_array( me, victim->query_netdead_enemy() ) == -1 )
        return;     // can't start fight if the victim is already netdead
    }

    if( !me->visible(victim)
    && (random(100 + (int)me->query_skill("perception")) < 100) )
        return;

    // If victim is busy or unconcious, always take the chance to make an attack.
    // added: if victim is in "no_move", similar to "is_busy".
    if( victim->is_busy() || (victim->query_temp("no_move")) || !living(victim) ) {
        me->set_temp("guarding", 0);
        if( !victim->is_fighting(me) ) victim->fight_ob(me);
        do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);

    // Else, see if we are brave enough to make an aggressive action.
    } else if( random( (int)victim->query("cps") * 3 ) < ((int)me->query("cor") + (int)me->query("bellicosity") / 50) ) {
        me->set_temp("guarding", 0);
        if( !victim->is_fighting(me) ) victim->fight_ob(me);
        do_attack(me, victim, me->query_temp("weapon"), TYPE_REGULAR);

    // Else, we just start guarding.
    } else if( !me->query_temp("guarding") ) {
        me->set_temp("guarding", 1);
        message_vision( guard_msg[random(sizeof(guard_msg))], me, victim);
        return;
    } else return;
}

//  auto_fight()
//
//  This function is to start an automatically fight. Currently this is
//  used in "aggressive", "vendetta", "hatred", "berserk" fight.
//
void auto_fight(object me, object obj, string type)
{
    // Don't let NPC autofight NPC.
    if( !userp(me) && !userp(obj) ) return;

    // Because most of the cases that we cannot start a fight cannot be checked
    // before we really call the kill_ob(), so we just make sure we have no 
    // aggressive callout wating here.
    if( me->query_temp("looking_for_trouble") ) return;
    me->set_temp("looking_for_trouble", 1);

    // This call_out gives victim a chance to slip trough the fierce guys.
    call_out( "start_" + type, 0, me, obj);
}

void start_berserk(object me, object obj)
{
    int bellicosity;

    if( !me ) return;// Are we still exist( not becoming a corpse )?
    me->set_temp("looking_for_trouble", 0);
    if( !obj ) return;

    if( wizardp(obj) ) return;  

    if( me->is_fighting(obj)                // Are we busy fighting?
    ||  !living(me)                         // Are we capable for a fight?
    ||  environment(me)!=environment(obj)   // Are we still in the same room?
    ||  environment(me)->query("no_fight")  // Are we in a peace room?
    )   return;

    bellicosity = (int)me->query("bellicosity");
    message_vision("$N用一种异样的眼神扫视着在场的每一个人。\n", me);

    if( (int)me->query("force") > (random(bellicosity) + bellicosity)/2 ) return;

    if( bellicosity > (int)me->query("score") 
    &&  !wizardp(obj) ) {

        // auto kill, mark my_killer_list. -- mon 9/23/98
//      if(userp(me) && userp(obj)) {
//      set_my_killer_list(me, obj);
//      }

        message_vision("$N对着$n喝道：" + RANK_D->query_self_rude(me)
        + "看你实在很不顺眼，去死吧。\n", me, obj);
        me->kill_ob(obj);
    } else {
        message_vision("$N对着$n喝道：喂！" + RANK_D->query_rude(obj)
            + "，" + RANK_D->query_self_rude(me) + "正想找人打架，陪我玩两手吧！\n",
            me, obj);
        me->fight_ob(obj);
    }
}

void start_hatred(object me, object obj)
{
    if( !me || !obj ) return;               // Are we still exist( not becoming a corpse )?

    me->set_temp("looking_for_trouble", 0);

    if( me->is_fighting(obj)                // Are we busy fighting?
    ||  !living(me)                         // Are we capable for a fight?
    ||  environment(me)!=environment(obj)   // Are we still in the same room?
    ||  environment(me)->query("no_fight")  // Are we in a peace room?
    )   return;

    // We found our hatred! Charge!
    message_vision( catch_hunt_msg[random(sizeof(catch_hunt_msg))], me, obj);
    me->kill_ob(obj);
}

void start_vendetta(object me, object obj)
{
    if( !me || !obj ) return;               // Are we still exist( not becoming a corpse )?

    me->set_temp("looking_for_trouble", 0);

    if( me->is_fighting(obj)                // Are we busy fighting?
    ||  !living(me)                         // Are we capable for a fight?
    ||  environment(me)!=environment(obj)   // Are we still in the same room?
    ||  environment(me)->query("no_fight")  // Are we in a peace room?
    )   return;

    // We found our vendetta opponent! Charge!
    me->kill_ob(obj);
}

void start_aggressive(object me, object obj)
{
    if( !me || !obj ) return;               // Are we still exist( not becoming a corpse )?

    me->set_temp("looking_for_trouble", 0);

    if( me->is_fighting(obj)                // Are we busy fighting?
    ||  !living(me)                         // Are we capable for a fight?
    ||  environment(me)!=environment(obj)   // Are we still in the same room?
    ||  environment(me)->query("no_fight")  // Are we in a peace room?
    )   return;

    // We got a nice victim! Kill him/her/it!!!
    me->kill_ob(obj);
}

// This function is to announce the special events of the combat.
// This should be moved to another daemon in the future.
void announce(object ob, string event, string msg)
{
    switch(event) {
        case "dead":
            message_vision("\n$N死了。\n\n", ob);
            break;
        case "unconcious":
            message_vision("\n$N脚下一个不稳，跌在地上一动也不动了。\n\n", ob);
            break;
        case "revive":
            message_vision("\n$N慢慢睁开眼睛，清醒了过来。\n\n", ob);
            break;
                case "death_rumor":
            CHANNEL_D->do_channel(this_object(),"rumor",msg);
            break;
    }
}

void winner_reward(object killer, object victim)
{
    killer->defeated_enemy(victim);
}

void killer_reward(object killer, object victim)
{
    int bls;
    string vmark;
    int gain,gain1,lose,pos_reward;
    string str,killerid;

    // Call the mudlib killer apply.
    killer->killed_enemy(victim);

    if( userp(victim) ) { // victim is user.
        
//      string *my_killer_list;
        int init_killer;
        int no_pk;
        string actsname;

       killer->add("PKS", 1);
       victim->clear_condition();
       // beeby 7/14/2000
       // Add victim's 妖气或仙气
       pos_reward=victim->query("position")*5/100;
       if ( pos_reward >= 0 )
          pos_reward=(pos_reward<20)?20:pos_reward;
       else
          pos_reward=(pos_reward>-20)?-20:pos_reward;
           victim->add("position",pos_reward);
       // Give the death penalty to the dying user.
       victim->set("bellicosity", 0);
       
       killerid=killer->query("id");
 
       // mon 8/4/98
       // to see whether the killer has init the kill on me.
       // if yes, then this is PK. (init_killer!=-1)
       // if no, (means the victim init the kill and got killed),
       // then treat this as normal death. (init_killer==-1)
//     my_killer_list=victim->query_temp("my_killer_list");
//     victim->delete_temp("my_killer_list");

//     if(!my_killer_list) init_killer=-1;
//     else init_killer=member_array(killerid, my_killer_list);
        
       no_pk=killer->query_condition("no_pk_time");
//     if(no_pk>10) init_killer=1; // killed by a player who
       // has PK record, then this is PK.
           // regardless who init it.

//           if(userp(killer) && init_killer!=-1) { // killer is user.
           if(userp(killer)) { // killer is user.
         killer->apply_condition("no_pk_time",240+no_pk);
         killer->add("position",- pos_reward);
         
           //limit on how many one can pk in a row.
             lose=victim_lose(killer,victim,killerid);
         gain=lose*8/10;
         if(gain<0) gain=0;
         victim->delete_temp("last_fainted_from");
         /*
         if(killerid==victim->query("kill/last_killer")) {
           //discourage repeated killing same player.
           gain1=victim->query("kill/last_lose")/2;
               if(gain>gain1) {
             gain=gain1;
               }
             }
         */
         if(lose>100)
           killer->delete("kill/last_killer");
         //any one can kill this killer to
         //get maximum dx benefit.
         //including the one who last killed 
         //this killer.
         //here check lose>100, so one can't
         //pk a newbie to erase the last_killer flag.
         killer->add("kill/pkgain",gain);
         killer->add("daoxing",gain);

         victim->set("kill/last_killer",killerid);
         //the victim is protected for repeated
         //killing by the same killer.
         victim->set("kill/last_lose",gain);
         //actually last_lose is what the killer gains,
         //not really the victim lose.
         //victim loss is in /death/combat_exp_loss
//       victim->add("kill/pklose",lose);
//       victim->add("daoxing",-lose);
             
         //for death recovery.
//             victim->set("death/mud_age",victim->query("mud_age"));
//             victim->set("death/combat_exp_loss",lose);
//       victim->set("death/skill_loss",0);
//       log_file("death",victim->query("id")+
//         " lost "+lose+" dx points and no skill lose.(pk)\n");
         
         victim_penalty(victim);

             str=chinese_daoxing(gain);
             if(strlen(str)>1) {
               str=killer->name(1)+"得到"+str+"道行！";
             }
         
         if (!(actsname=killer->query_temp("action_name")))
            actsname="";
         else
        actsname="以一招"+HIC+actsname+HIM+"给";
         str=victim->name(1)+"在"+HIW+
                 MISC_D->find_place(environment(victim))
                 +environment(victim)->query("short")
                 +HIM+"被"+killer->name(1)+
             actsname+"吃掉了。"+str;
         CHANNEL_D->do_channel(this_object(), "rumor",str);
         bls=10;
           } else {    // killer is not user or killer didn't init the kill.

           int i;
           string last_faint;
           object fainter;
           // mon 8/1/98
           // check who fainted the victim.
           // if it was a player faint the victim,
           // give the player credit for pk :)
           last_faint=victim->query_temp("last_fainted_from");
           if(last_faint) {
           fainter=find_player(last_faint);
           if(fainter && userp(fainter)) {
//               if(!my_killer_list) init_killer=-1;
//               else init_killer=
//           member_array(last_faint, my_killer_list);

//           if(init_killer!=-1)
                       fainter->apply_condition("no_pk_time",240+
                     fainter->query_condition("no_pk_time"));
           }
           }

           i=victim->query_condition("no_pk_time");
           if(i>240) victim->apply_condition("no_pk_time",i-80);

               victim_penalty(victim);

        bls = 10;
                
        if (!(actsname=killer->query_temp("action_name")))
                     actsname="";
        else
             actsname="以一招"+HIC+actsname+HIM;
        actsname=victim->name(1)+"在"+HIW+
            MISC_D->find_place(environment(victim))
                    +environment(victim)->query("short")+HIM+
            "被"+killer->name(1)+actsname+"杀死了";


        CHANNEL_D->do_channel(this_object(), "rumor",actsname);
//        sprintf("%s被%s%s杀死了。", victim->name(1), killer->name(2),actsname));
           }
    } else {  //NPC is the victim.
      if(userp(killer)) {
                int reward;

        reward=nk_gain(killer, victim);
        pos_reward=victim->query("position")<0?1:-1;
        killer->add("position",pos_reward);
        if(reward>0) {
          string msg;
                  killer->add("kill/nkgain",reward);
          killer->add("daoxing",reward);
                  str=chinese_daoxing(reward);
                  tell_object(killer,"\n你得到了"+str+"道行。\n");
          msg=sprintf("%s(%d)杀死了%s(%d)，得到%d点道行。", 
            killer->query("id"),(killer->query("daoxing")+
            killer->query("combat_exp"))/2, 
            victim->query("id"),(victim->query("daoxing")+
            victim->query("combat_exp"))/2,reward);
          log_file("npc_kill","["+ctime(time())+"] "+msg+"\n");
          CHANNEL_D->do_channel(this_object(), "sys",msg);
        }
      }
      killer->add("MKS", 1);
      bls = 1;
    }

        if(!userp(killer) &&
       ((killer->query("daoxing")+killer->query("combat_exp"))/10>
        (victim->query("daoxing")+victim->query("combat_exp"))) ) bls=0;
        //mon 2/15/98
    //can't use newbie to kill NPC to increase NPC's bls.

    // NPC got 10 times of bellicosity than user.
    killer->add("bellicosity", bls * (userp(killer)? 1: 10));

    if( stringp(vmark = victim->query("vendetta_mark")) )
        killer->add("vendetta/" + vmark, 1);
    killer->delete_temp("action_name");
        if(userp(killer)) killer->save();
    if(userp(victim)) victim->save();
}

void victim_penalty(object victim)
{
    // by snowcat 2/21/1998 for death/*
    int combat_exp_loss = (int)victim->query("combat_exp") / 40;
    int dx_loss = (int)victim->query("daoxing") / 40;

        victim->set("death/mud_age",victim->query("mud_age"));
        victim->set("death/combat_exp_loss",combat_exp_loss);
        victim->set("death/dx_loss",dx_loss);
    log_file("death",victim->query("id")+
      " lost "+combat_exp_loss+" exp points and "
      + dx_loss+ " dx points.\n");

    victim->add("combat_exp", -combat_exp_loss);
    victim->add("daoxing", -dx_loss);
    victim->delete("vendetta");
    if( victim->query("thief") )
        victim->set("thief", (int)victim->query("thief") / 2);
    if( (int)victim->query("potential") > (int)victim->query("learned_points"))
        victim->add("potential",
            ((int)victim->query("learned_points") - (int)victim->query("potential"))/2 );
        if(random(100)>(int)victim->query("kar")) {
          victim->set("death/skill_loss",1);
      victim->skill_death_penalty();
    } else
      victim->set("death/skill_loss",0);

        victim->save();
}

int nk_gain(object killer, object victim)
{
        string fam, fam1;
        int cla, eff_dx, eff1, eff2, dx, reward, nkgain;

        // some NPC has no rewards.
        // mon 3/9/99
        if(victim->query("no_nk_reward")) return 0;

            //can't kill NPCs which were fainted by
        //other players to get daoxing.
            if(victim->query_temp("last_fainted_from")
               && victim->query_temp("last_fainted_from")!=
               killer->query("id")) return 0;

            fam=killer->query("family/family_name");

        if(fam && !undefinedp(family[fam])) {//player must have a
                                             //family.
              cla=family[fam];
              eff_dx=victim->query("eff_dx");
          nkgain=victim->query("nkgain");

              //can't kill NPCs of the same menpai as the player
          //to get daoxing.
          fam1=victim->query("family/family_name");
          if(fam1 && fam==fam1)
            return 0;

              if(eff_dx!=0 && cla*eff_dx>0)
            return 0;
        //for NPC being set eff_dx, only 
        //if cla*eff_dx<=0 (not all in xian or all in yao)
        //can gain daoxing.

              //For NPC which has not been set eff_dx,
          //the default is everyone can kill them to get
          //dx reward, however, the default value is low.
          if(!eff_dx) { 
            //default value for eff_dx and nkgain.
        //the default nkgain is low.
        //If want to increase the value for certain NPC,
        //then need to set its eff_dx and nkgain.

                int dxn=0;

        eff_dx=(victim->query("daoxing")+
            victim->query("combat_exp"))/2;
                if(eff_dx>20000)
          dxn=eff_dx/3;
        else if(eff_dx>5000)
          dxn=eff_dx/2;
                else 
          dxn=eff_dx;
          //make it easier for newbie.
                eff_dx=dxn;
              }

          if(!nkgain) {
            int effdx=eff_dx;

        if(effdx<0) effdx=-effdx;

        if(effdx>667000) 
          nkgain=600;
                else if(effdx>333000)
          nkgain=500;
                else if(effdx>100000)
          nkgain=400;
                else if(effdx>33000)
          nkgain=300;
                else if(effdx>17000)
          nkgain=200;
                else if(effdx>5000)
          nkgain=150;
                else if(effdx>2000)
          nkgain=100;
                else if(effdx>500)
          nkgain=50;
                else nkgain=25;

        nkgain=nkgain+20;
          }

                if(eff_dx<0) eff_dx=-eff_dx;
                eff1=eff_dx/8;
        eff2=eff_dx/4;
        dx=(killer->query("daoxing")+
            killer->query("combat_exp"))/2;
        if(dx>eff_dx) reward=0;
        else if(dx>eff2) reward=nkgain;
        else if(dx>eff1) reward=10*(dx-eff1)/(eff2-eff1)*
          nkgain/10;
                else reward=0;

        if(cla==0 || (cla!=0 && !fam1)) reward=reward*2/3;
        //cla==0: people not xian and not yao. e.g. longgong, moon.
        //cla!=0: people either xian or yao. if they kill
        //        no family NPC, dx reward reduse.

        return reward;
             
            }
        return 0;
}

int victim_lose(object killer,object victim,string killerid) 
{            int lose,exp_k,exp_v;
             int lose1;

             if((wizardp(victim)&&!wizardp(killer))
            ||(!wizardp(victim)&&wizardp(killer)))
        return 0;

             if(victim->query_temp("last_fainted_from")
               && victim->query_temp("last_fainted_from")!=
               killerid) {
               lose=0;
             } else {
               exp_k=killer->query("daoxing");
               exp_v=victim->query("daoxing");
               if (exp_k>exp_v) {
                 lose=10*exp_v/(exp_k+1)*(4000+exp_v)/500;
          // a exp_v/exp_k pre-factor.
         if(exp_k>exp_v*4) lose=0;
         // if less then 1/4 dx, then no damage.
               } else {
                 lose=(4000+exp_v)/50;  // about 2% lose for victim.
               }
               if(lose<0) lose=0;
               if(lose>exp_v) lose=exp_v;
             }
         
         // this is the maximum lose.
         lose1=(int)victim->query("daoxing") / 40;
         if(lose>lose1) lose=lose1;
         
         return lose;
}

string chinese_daoxing(int gain)
{            int year,day,hour;
             string str;

             year=gain/1000;
             day=(gain-year*1000)/4;
             hour=(gain-year*1000-day*4)*3;
             str="";
             if(year) str=str+chinese_number(year)+"年";
             if(day) str=str+chinese_number(day)+"天";
             if(hour) str=str+chinese_number(hour)+"时辰";

             return str;
}

int check_family(string fam)
{
    if(fam && !undefinedp(family[fam]))
      return family[fam];
    else
      return 0;
}


//the following functions are for performs...weiqi
//copy and modified from spelld.c

int attacking_perform_success(object attacker, object target, int skill_level, int success_adj)
{
        int ap, dp, success;
 
        ap = ( skill_level * skill_level * skill_level / 10 ); //this is from skill.
        //at high exp, the skill level can not follow, so need adjustment here.
        ap = ap*(1+attacker->query("combat_exp")/500000);
        ap = ap+attacker->query("combat_exp");
        dp = target->query("combat_exp");

        success = 0;

        if ( success_adj < 20 ) success_adj = 20;
        else if( success_adj > 500 ) success_adj = 500;

        ap = ap*success_adj/100;

        if( random(100)>dp*100/(ap+dp) ) success = 1;

        return success;
}

int attacking_perform_damage(object attacker, object target, int damage_adj)
{
        int a_neili, d_neili, damage;

        if( damage_adj < 50 ) damage_adj = 50;
        else if( damage_adj > 200 ) damage_adj = 200;

        //will use current neili...but do not allow it exceeds 2 time of the max.
        a_neili = attacker->query("force");
        if( a_neili > 2*attacker->query("max_force") ) a_neili = 2*attacker->query("max_force");
        d_neili = target->query("force");
        if( d_neili > 2*target->query("max_force") ) d_neili = 2*target->query("max_force");


        //neili and qi. weaker than cast here...
        damage = (a_neili - d_neili)/30 + 
                random(attacker->query("eff_kee") / 30)-random(target->query("eff_kee") / 30);

        //mana_factor, here the attacker has some advantage.
        //the damage_adj higher, the better for attacker.
        damage += (3*damage_adj/200) //weaker than cast here...
                *( attacker->query("force_factor") - random(target->query("force_factor")) );

        //for backfire, we need let it be serious...
        if( damage < 0 ) damage = damage - target->query("force_factor"); 
        //here increase the damage, since previously it's included in random()

        damage = damage*damage_adj/100; //last damage scaled again.

        //finally, we need let the force level useful...
        //the setting is, at enabled level 200, the damage will double.
        if( damage > 0 )
        {
                damage += (damage*(int)attacker->query_skill("force"))/200;
        }
        else if ( damage < 0 )
        {
                damage += (damage*(int)target->query_skill("force"))/200;
        }
    
    
        return damage;
}

/*
weiqi 981206
attacking-cast...called from spells function.
modified for perform...
a typical call would be:

        COMBAT_D->attacking_perform(
                me, 
                        //attacker 
                target, 
                        //target
        skill_level, 
            //level of skill used
                success_adj, 
                        //success adjustment
                damage_adj, 
                        //damage adjustment
                "both", 
                        //damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
                HIC "$N几个指头迅速捻动，突然张嘴一喷！红橙黄三道火焰呼！地一声向$n卷去！\n" NOR,
                        //initial message
                HIC "结果$n被烧得焦头烂额！\n" NOR, 
                        //success message
                HIC "但是$n轻轻一跳就躲了开来。\n" NOR, 
                        //fail message
                HIC "但是火焰被$n以法力一逼，反向$N回卷而去！\n" NOR, 
                        //backfire initial message
                HIC "结果太乙真火反噬，$n被烧得焦头烂额！\n" NOR
                        //backfire hit message. note here $N and $n!!!
        );
*/
void attacking_perform(
        object attacker, 
        object target, 
    int skill_level,//the level of skill used to attack.
        int success_adj, 
        int damage_adj, //default value is 100 for this 2 parameters.
        string damage_type, //must be "shen"/"sen", "qi"/"kee" or "both"(default)
        string msg_init, 
        string msg_success, 
        string msg_fail, 
        string msg_backfire_init,
        string msg_backfire_success)
{
        int damage;

        //first, show the initial message...
        message_vision( msg_init, attacker, target );

        //calculate if the casting can happen...
        if( attacking_perform_success(attacker, target, skill_level, success_adj) == 0 )
        {
                message_vision( msg_fail, attacker, target );
                //let the target kill attacker.
                target->kill_ob(attacker);
                return;
        }

        damage = attacking_perform_damage(attacker, target, damage_adj);

        if( damage > 0 ) //attacker hit target
                SPELL_D->apply_damage(attacker, target, damage, damage_type, msg_success);

        else if( damage < 0 ) //backfire
        {
                message_vision(msg_backfire_init, attacker, target);
                SPELL_D->apply_damage(target, attacker, -damage, damage_type, msg_backfire_success);
        }

        else //damge=0
        message_vision(HIB "结果正好被$N以内力逼住，谁也没有吃亏。\n" NOR, target);

        //let the target kill attacker.
        target->kill_ob(attacker);

        return;
}

int do_attack_damage(object me, object victim, object weapon)//调动此函数，相当于直接打中敌人，敌人一样会受到伤害
{

        mapping my, your, action, victim_action;
	string  result;
	string attack_skill, force_skill, martial_skill, dodge_skill, parry_skill;
	mixed foo;
	int damage, damage_bonus, defense_factor;
my = me->query_entire_dbase();
your = victim->query_entire_dbase();	
action = me->query("actions");
damage = me->query_temp("apply/damage");
damage = (damage + random(damage)) / 2;
if( action["damage"] )
        damage += action["damage"] * damage / 100;

	damage_bonus = me->query_str();

	// Let force skill take effect.
	if( my["force_factor"] && (my["force"] > my["force_factor"]) ) {
	if( force_skill = me->query_skill_mapped("force") ) {
			foo = SKILL_D(force_skill)->hit_ob(me, victim, damage_bonus, my["force_factor"]);
			if( stringp(foo) ) result += foo;
				else if( intp(foo) ) damage_bonus += foo;
				}
			}

			if( action["force"] )
				damage_bonus += action["force"] * damage_bonus / 100;

			if( martial_skill = me->query_skill_mapped(attack_skill) ) {
				foo = SKILL_D(martial_skill)->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			}

			// Let weapon or monster have their special damage.
			if( weapon ) {
				foo = weapon->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo;
			} else {
				foo = me->hit_ob(me, victim, damage_bonus);
				if( stringp(foo) ) result += foo;
				else if(intp(foo) ) damage_bonus += foo * 3 / 4;
			}

			if( damage_bonus > 0 )
				damage += (damage_bonus + random(damage_bonus))/2;
			if( damage < 0 ) damage = 0;

			// Let combat exp take effect
			defense_factor = your["combat_exp"];
			while( random(defense_factor) > my["combat_exp"] ) {
				damage -= damage / 3;}
			
			
                    damage = victim->receive_damage("kee", damage, me );
			
			if( (me->is_killing(victim) || weapon)
			&& random(damage) > (int)victim->query_temp("apply/armor") ) {
				// We are sure that damage is greater than victim's armor here.
				victim->receive_wound("kee",
					damage - (int)victim->query_temp("apply/armor"), me);
				//wounded = 1;
				}
			return damage;	
}
