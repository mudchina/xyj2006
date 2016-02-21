// fangzhang, the one in jail.
// created by mes, updated 6-21-97 pickle

/************************************************************/
#include <ansi.h>
inherit NPC;

string quest_complete();
int award(object me);
void destroy(object ob);
int annouce_adjust(object me);
string answer();
string check_gift();
int do_add(string arg);
int do_subtract(string arg);
int do_finalized(string arg);

string method="
具体指令如下：

降低天赋：subtract <arg>
增加天赋：add <arg>
检查情况：state
决定接受：finalize

这里的 <arg> 是天赋的缩写：

膂力：str    胆识：cor    悟性：int    灵性：spi
定力：cps    容貌：per    根骨：con    福缘：kar

";
int total = 0;
int credit = 0;
mapping points=([]);
mapping gift=([
	"str"		: "膂力",
	"cor"		: "胆识",
	"int"		: "悟性",
	"spi"		: "灵性",
	"cps"		: "定力",
	"per"		: "容貌",
	"con"		: "根骨",
	"kar"		: "福缘",
]);
string *gift_name=({ "kar", "con", "per", "cps", "spi", "int", "cor", "str", });
/************************************************************/
void create()
{
  set_name("圆清",({"yuan qing", "yuan", "qing", "fang zhang", "monk", "yuanqing"}));
  set("title","方丈");
  set("gender", "男性");
  set("age", 80);
  set("long","一个削瘦的老和尚，似乎被吓疯了。\n");
  set("combat_exp",5000);
  set("str",30);
  set("per",30);
  set("int",30);
  set("attitude", "peaceful");
  set("inquiry", ([
		   "name"   : "唉！老纳本是灵云寺的圆清长老。",
		   "here"   : "我也不知道怎么回事。那天晚上我正念佛呢，突然就被一阵阴风刮这里来了。",
		   "rumors" : "我连自己的生死都不知，还有什么闲心去打听别的？",
		   "生死"   : "也不知有没有哪位英雄肯来搭救我。唉！",
		   "rescue" : (: quest_complete :),
		   "搭救"   : (: quest_complete :),
		   "修改"   : (: answer :),
		   "xiugai" : (: answer :),
		   "天赋"   : (: check_gift :),
		   "tianfu" : (: check_gift :),
		   ]));
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
}
/************************************************************/
void init()
{
    add_action("do_add", "add");
    add_action("do_add", "jia");
    add_action("do_subtract", "subtract");
    add_action("do_subtract", "jian");
    add_action("do_state", "state");
    add_action("do_state", "chakan");
    add_action("do_finalize", "finalize");
    add_action("do_finalize", "jueding");
}
/************************************************************/
string quest_complete()
{
  object monk=this_object(), me=this_player();
  string served;

  if (stringp(served=query("serving"))
   && served != me->query("id"))
    if (present(served, environment(monk)))
    {
	return "多谢施主好意，但已有人答应带老衲出去。";
    }
  if (me->query("obstacle/wudidong") == "done")
  {
      tell_object (me,"你已经过了这一关，什么都得不到了！\n");
      return "这．．．";
  }
  if (served==me->query("id"))
	return "阿弥陀佛，施主不是已经答应带老衲出去了么？";
  if (!wizardp(me) || !me->query("env/immortal"))
/*
  if (!me->query_temp("mark/wudidong_opened_door")
    || me->query_temp("mark/wudidong_no_hope_of_knowing_trap"))
  {
      command("say 你、你、你，你是谁？哦，你是来救我的？看你这样子不象啊？");
      command("say 你也是被别人打晕了背进来的吧？我要是跟你出去了，还得给抓回来。");
      return "阿弥陀佛，我佛慈悲！贫僧的这张草铺就让给你吧。";
  }
*/
  me->set_temp("wudidong/can_ask_monk");
  set("serving", me->query("id"));
  call_out("announce_adjustment", 1, me);
  return "这位施主是来搭救于我的？";
}
string answer()
{
    object me=this_player();

    if (!me->query_temp("wudidong/ready_to_change_gifts"))
	return "我也不清楚。";
    tell_object(me, method);
    return "施主可要三思而后行啊！";
}
string check_gift()
{
    object me=this_player();
    string msg;
    int i=sizeof(gift_name);

    if (!me->query_temp("wudidong/ready_to_change_gifts"))
	return "我也不清楚。";
    msg="你目前的天赋如下：\n\n";
    while (i--)
    {
	msg += gift[gift_name[i]]+"：["+me->query(gift_name[i])+"]";
	if (i==4) msg += "\n";
	else msg += "\t";
    }
    msg += "\n";
    tell_object(me, msg);
    return "施主可要三思而后行啊！";
}

int announce_adjustment(object me)
{
    object monk=this_object();
    string myrespect=RANK_D->query_respect(me), msg;

    command("say 这、这、这，老衲可真不知怎么感谢"+myrespect+"才好了！");
    command("consider");
    command("say 先师圆寂前传给老衲些许法术，也许能够帮助"+myrespect+"改变一些先天的能力。\n");
    msg=monk->name()+"答应帮助你从新调整天赋！\n";
    msg+="你一共可以改变三点天赋，先由某一项上减掉，再加到另一项上。\n";
    msg+=method;
    tell_object(me, msg);
    tell_object(me, CYN+monk->name()+"附耳道："+myrespect+"若是不知怎么修改天赋，或想知道现在天赋如何，可以问我。\n"NOR);
    me->set_temp("wudidong/ready_to_change_gifts", 1);
    return 1;
}
int do_subtract(string arg)
{
    object me=this_player();
    if (this_player()->query("id")!=query("serving"))
	return 0;
    if (!me->query_temp("wudidong/ready_to_change_gifts"))
	return 0;
    if (!arg) return notify_fail("请选择你要降低的天赋。 (ask monk about 天赋)\n");
    if(arg != "str"
    && arg != "cor"
    && arg != "int"
    && arg != "spi"
    && arg != "cps"
    && arg != "per"
    && arg != "con"
    && arg != "kar")
	return notify_fail("这个 "+arg+" 不是一项天赋。\n"); 
    if (credit >= 3)
	return notify_fail("你总共只能改变三点天赋，请用 state 查你现在的选择。\n");
    if (total >= 3)
	return notify_fail("你总共只能改变三点天赋，请用 state 查你现在的选择。\n");
    if (me->query(arg) <= 10)
	return notify_fail("你不能将一项天赋降低到十点以下。(ask monk about 天赋)\n");
    credit++;
    total+=1;
    points[arg]-=1;
    tell_object(me, "你决定降低一点"+gift[arg]+"！你现在还有"+chinese_number(total)+"点潜能可以分配。\n");
    return 1;
}
int do_add(string arg)
{
    object me=this_player();
    if (this_player()->query("id")!=query("serving"))
	return 0;
    if (!me->query_temp("wudidong/ready_to_change_gifts"))
	return 0;

    if (!arg) return notify_fail("请选择你要增加的天赋。 (ask monk about 天赋)\n");
    if (member_array(arg, gift_name) == -1)
	return notify_fail("这个 "+arg+" 不是一项天赋。\n"); 
    if (total <= 0)
	return notify_fail("你总共只能改变三点天赋，请用 state 查你现在的选择。\n");
    if (me->query(arg) >= 30)
	return notify_fail("你不能将一项天赋增加到三十点以上。(ask monk about 天赋)\n");
    total-=1;
    points[arg]+=1;
    tell_object(me, "你决定增加一点"+gift[arg]+"！你现在还有"+chinese_number(total)+"点潜能可以分配。\n");
    return 1;
}
/************************************************************/
int do_state(string arg)
{
    object me=this_player();
    string msg;
    int i=sizeof(gift_name), count;

    if (this_player()->query("id")!=query("serving"))
	return 0;
    if (!me->query_temp("wudidong/ready_to_change_gifts"))
	return 0;
    msg="你目前还有"+chinese_number(total)+"点天赋可以分配。\n";
    while(i--)
    {
	if((count=points[gift_name[i]]) > 0)
	    msg+="你准备将"
		+gift[gift_name[i]]
		+"增加"
		+chinese_number(count)
		+"点。\n";
	else if(count < 0)
	    msg+="你准备将"
		+gift[gift_name[i]]
		+"降低"
		+chinese_number(-count)
		+"点。\n";
	continue;
    }
    tell_object(me, msg);
    return 1;
}
int do_finalize(string arg)
{
    object me=this_player();
    string msg;
    int i=sizeof(gift_name), count;
    if (me->query_temp("wudidong/doing"))
       return 0;
    me->set_temp("wudidong/doing",1);
    if (this_player()->query("id")!=query("serving"))
	return 0;
    if (!me->query_temp("wudidong/ready_to_change_gifts"))
	return 0;
    msg=YEL+this_object()->name()+"口中念念有词，伸手向$N一指，喝声「疾」！\n"NOR;
    message_vision(msg, me);
    while(i--)
    {
	if(!count=points[gift_name[i]])
	    continue;
	me->add("gift_adjust/"+gift_name[i], count);
	me->add(gift_name[i], count);
	if (count >= 0)
		tell_object(me, YEL"你的"+gift[gift_name[i]]+"被增加了"+
			chinese_number(points[gift_name[i]])+
			"点！\n"NOR);
	else
		tell_object(me, YEL"你的"+gift[gift_name[i]]+"被减少了"+
			chinese_number(-points[gift_name[i]])+
			"点！\n"NOR);
	continue;
    }
    tell_object(me, YEL"恭喜！你的天赋改变了！\n"NOR);
    call_out("award", 1, me);
    return 1;
}

int award(object me)
{
  object monk=this_object();
  string myid=me->query("id"), myname=me->query("name");
  int year, day, hour, reward, mykar=me->query_kar();

  command("thank " + myid);
  command("say 老纳这就起程回寺！");
  command("south");
  call_out ("destroy",2, monk);	
/*  if (me->query_temp("mark/wudidong_gift")!=1 && random(mykar)>10)
  {
      command("say 这位" + myrespect +"和我有缘。这是家传之宝，赠于" + RANK_D->query_respect(me) +"，略表寸心。\n");
      carry_object("/d/obj/magic/baguafu");
      command("give bagua to " + myid);
      me->add_temp("mark/wudidong_gift", 1);
  }
*/
  me->add("obstacle/number",1);
  me->set("obstacle/wudidong","done");
  me->delete_temp("mark/wudidong_opened_door");
  reward=4000+random((mykar-10)*80);
  year = reward / 1000;
  day = (reward - year * 1000) / 4;
  hour = (reward - year * 1000 - day * 4) * 3; 
  tell_object (me,"你赢得了"+chinese_number(year)+"年"+chinese_number(day)+"天"+chinese_number(hour)+"时辰的道行！\n");
  command("rumor 听说"+myname+"独闯无底洞，救出了玉鼠精抓去的一个老和尚，也不知是真是假。");
  me->add("daoxing",reward);
  me->save();
  log_file("obstacle","["+ctime(time())+"] "+sprintf("%s(%s)过了无底洞,得到了%d 点道行\n",
 me->query("name"),me->query("id"),reward));

  return 1;
}
void destroy(object ob)
{
  destruct(ob);
  return;
}
/************************************************************/
