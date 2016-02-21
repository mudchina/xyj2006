//by happ@YSZZ
#include <ansi.h>
inherit NPC;
#include <reporting.h>
string * degree_desc = ({
       GRN "从九品下 归德执戟长上" NOR,
       YEL "从九品下 将仕郎" NOR,
       RED "从九品下 陪戎副尉" NOR,
       GRN "从九品上 文林郎" NOR,
       CYN "从九品上 陪戎校尉" NOR,
       CYN "正九品下 登仕郎" NOR,
       GRN "正九品下 怀化执戟长上" NOR,
       CYN "正九品上 仁勇副尉" NOR,
       RED "正九品上 仁勇校尉" NOR,
       GRN "正九品上 儒林郎" NOR,
       YEL "从八品下 承务郎" NOR,
       MAG "从八品下 归德司戈" NOR,
       CYN "从八品下 御侮副尉" NOR,
       RED "从八品上 承奉郎" NOR,
       GRN "从八品上 御侮校尉" NOR,
       YEL "正八品下 征事郎" NOR,
       MAG "正八品下 怀化司戈" NOR,
       CYN "正八品下 宣节副尉" NOR,
       RED "正八品上 给事郎" NOR,
       GRN "正八品上 宣节校尉" NOR,
       YEL "从七品下 宣议郎" NOR,
       MAG "从七品下 归德中侯" NOR,
       CYN "从七品下 翊麾副尉" NOR,
       RED "从七品上 朝散郎" NOR,
       GRN "从七品上 翊麾校尉" NOR,
       RED "从七品 武骑尉" NOR,
       YEL "正七品下 宣德郎" NOR,
       MAG "正七品下 怀化中侯" NOR,
       CYN "正七品下 致果副尉" NOR,
       RED "正七品上 朝请郎" NOR,
       GRN "正七品上 致果校尉" NOR,
       GRN "正七品 云骑尉" NOR,
       YEL "从六品下 通直郎" NOR,
       MAG "从六品下 归德司阶" NOR,
       CYN "从六品下 振威副尉" NOR,
       RED "从六品上 奉议郎" NOR,
       GRN "从六品上 振威校尉" NOR,
       YEL "从六品 飞骑尉" NOR,
       YEL "正六品下 承议郎" NOR,
       MAG "正六品下 怀化司阶" NOR,
       CYN "正六品下 昭武副尉" NOR,
       RED "正六品上 朝议郎" NOR,
       GRN "正六品上 昭武校尉" NOR,
       MAG "正六品 骁骑尉" NOR,
       YEL "从五品下 朝散大夫" NOR,
       MAG "从五品下 归德郎将" NOR,
       CYN "从五品下 游击将军" NOR,
       RED "从五品上 朝请大夫" NOR,
       GRN "从五品上 游骑将军" NOR,
       CYN "从五品  骑都尉" NOR,
       YEL "正五品下 朝议大夫" NOR,
       MAG "正五品下 怀化郎将" NOR,
       CYN "正五品下 宁远将军" NOR,
       RED "正五品上 中散大夫" NOR,
       GRN "正五品上 定远将军" NOR,
       RED "正五品 上骑都尉" NOR,
       YEL "从四品下 中大夫" NOR,
       MAG "从四品下 归德中郎将" NOR,
       CYN "从四品下 明威将军" NOR,
       RED "从四品上 太中大夫" NOR,
       GRN "从四品上 宣威将军" NOR,
       MAG "从四品 轻车都尉" NOR,
       YEL "正四品下 通议大夫" NOR,
       MAG "正四品下 怀化中郎将" NOR,
       CYN "正四品下 壮武将军" NOR,
       RED "正四品上 正议大夫" NOR,
       GRN "正四品上 忠武将军" NOR,
       CYN "正四品  上轻车都尉" NOR,
       YEL "从三品 银青光禄大夫" NOR,
       MAG "从三品上 归德大将军" NOR,
       CYN "从三品上 云麾将军" NOR,
       MAG "从三品  护  军" NOR,
       GRN "正三品下 归德将军" NOR,
       RED "正三品下 怀化将军" NOR,
       MAG "正三品  上护军" NOR,
       YEL "正三品 金紫光禄大夫" NOR,
       MAG "正三品上 怀化大将军" NOR,
       CYN "正三品上 冠军大将军" NOR,
       MAG "从二品  柱  国" NOR,
       RED "从二品 光禄大夫" NOR,
       GRN "从二品 镇军大将军" NOR,
       YEL "正二品 特  进" NOR,
       MAG "正二品 上柱国" NOR,
       MAG "正二品 辅国大将军" NOR,
       CYN "从一品 开府仪同三司" NOR,
       RED "从一品 膘骑大将军" NOR,
       HIR "开国县男" NOR,
       HIG "开国县子" NOR,
       HIY "开国县伯" NOR,
       HIB "开国县侯" NOR,
       HIC "开国县公" NOR,
       HIR "开国郡公" NOR,
       HIG "国    公" NOR,
       HIY "郡    王" NOR,
       HIW "辅佐王" NOR,
});

#include <obstacle.h>
int ask_for_officer();
int ask_for_leave();
string try_me();


void create()
{
  set_name("徐茂功", ({ "xu maogong", "xu", "maogong", "da chen" }));
  set("title", "大臣");
  set("gender", "男性");
  set("age", 60);
  set("per", 30);
  set("combat_exp", 300000);
  set_skill("force", 80);
  set_skill("spells", 80);
  set_skill("unarmed", 80);
  set_skill("dodge", 80);
  set_skill("parry", 80);
  set("gin", 3000);
  set("max_gin", 3000);
  set("kee", 3000);
  set("max_kee", 3000);
  set("sen", 3000);
  set("max_sen", 3000);
  set("force", 1000);
  set("max_force", 1000);
  set("mana", 1000);
  set("max_mana", 1000);
  set("force_factor", 80);
  set("inquiry", ([
                "做官"     : (: ask_for_officer :),
                "当官"     : (: ask_for_officer :),
                "升官"     : (: ask_for_officer :),
                "官位"     : (: ask_for_officer :),
//                "俸禄"     : (: try_me :),

/*
                "辞职"     : (: ask_for_leave :),
                "告老还乡" : (: ask_for_leave :),
                "退休"     : (: ask_for_leave :),
*/
        ]) );
  setup();
  carry_object("/d/obj/cloth/jinpao")->wear();
}

int ask_for_officer()
{

        int lv,size1;
        object ob=this_player();
        lv = ob->query("office_number")/10;
        size1 = sizeof(obstacles);
        
        if (lv >= sizeof(degree_desc)) lv = sizeof(degree_desc)-1;


/*         if ( ob->query("office_number") == 0 )
        {
         command("say "+ob->query("name")+"你还是先去点个卯吧。\n");
        return 1;
        }
*/
        if ( time() - ob->query_temp("last_time/officer") < 120 )
	{
        command("say "+ob->query("name")+"，你烦不烦啊。\n");
        return 1;
        }
/*      if ( ob->query("obstacle/number") < size1)
    	{
        command("say "+ob->query("name")+"，你还是先去取完经再来当官也不迟啊。\n");
        return 1;
        }
*/

        ob->set_temp("last_time/officer",time());
        ob->set("degree", degree_desc[lv]);
        command("nod");
        command("smile");
message("channel:chat",HIY+"【圣旨】徐茂功(xu maogong)：今奉皇帝玉旨，加封"+ob->query("name")+"为"+degree_desc[lv]+HIY"，钦此！\n"+NOR,users());
        return 1;
}

int ask_for_leave()
{
        object ob = this_player();

        if( !ob->query("office_number") )
        {
        command("say 大胆刁民，居然想戏弄本大臣！！");
        return 1;
        }

        if( ob->query("office_number") < 400 )
        {
        command("? "+ob->query("id"));
        command("say 现在正是仕途得意之时，为何要辞官呢？");
        command("say 给个理由先！");
        return 1;
        }
        command("say "+ob->name()+"是我大唐不可多得的人材啊！");
         command("say 你真的要走吗？");
        write("(yes/no)：");
        input_to("check",ob);
        return 1;
}
void check(string arg, object ob)
{
        int i=ob->query("office_number");
        if( arg=="yes" )
        {
               command("sigh");
                command("say 既然你要走，我也就不强留了！");
                command("chat "+ob->name()+"决定退出官场，去隐居了！");
                command("say 我在相记钱庄给你存了点金子，可以养老用了。");
                ob->add("balance",i*10000);
                ob->set("degree","隐士");
//                ob->delete("office_number");
//                ob->set("title","隐士");
                return ;
        }

        else
        {
                command("angry");
                command("say 别拿我开心好不好？？？");
                command("say 毛病！");
                return ;
         }

        input_to("check",ob);
        return ;
}
void reward (object who)
{
  object me = this_object ();
  int points = who->query_temp("quest/reward_point");
  string channel = "sldh";
  string *channels = who->query("channels");

  if ( !pointerp(channels) || !sizeof(channels) )
    channels = ({ channel });
  else if (member_array(channel, channels) == -1)
    channels += ({ channel });

  who->set("channels",channels);

  points=40+points*4;

  message_vision ("$N对$n一拜：菩萨托陛下传法旨，赐"+RANK_D->query_respect(who)+
                  COMBAT_D->chinese_daoxing(points)+"道行！\n",me,who);
/*
  command (channel+" "+who->query("name")+who->query("quest/reason")+"陛下有旨，赐"+
           COMBAT_D->chinese_daoxing(points)+"道行！");
*/                  
  who->add("quest/gain/daoxing",points);
  reporting (who, who->query("quest/reason"), points, "点道行");
  who->add("daoxing",points);
}

string try_me()
{       object me;
	me = this_player();
	if ((int)me->query("combat_exp")<100000)
		return ("国家栋梁看重武学,你还是多在此方面多下苦功啊!\n");
        if(me->query("age")<16)
                return ("年级太小，别光想着银子。！\n");
        if((int)me->query("office_number")< 100){
        	return ("官位太小，何来俸禄！！！\n");
        }
        else
        if(!(int)me->query("officeage")){
                me->set("officeage",1);
		me->add("balance", 2000000);
		 return ("这是第一次俸禄多多努力哦．\n");
        }
        if((int)me->query("age") < (int)me->query("officeage")+16)
	{
        	if ((int)me->query("office_number")>1000)
			me->add("balance",10000000);
		else 
                        me->add("balance",(int)me->query("office_number")*10000);
         me ->add("officeage",1);
         return ("是时候了，这是你的俸银．\n");
   	}
        else
                me->add("money_get", 100);
                me->save();
                return ("俸禄刚送过，怎么又来要了？\n");
}



