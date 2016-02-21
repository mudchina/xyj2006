//投票箱简介
//可以自由增加投票信息（几种选择的信息）,统计投票结果，设置投票资格，
//自动储存投票资料。。。(档案将会储存在/data/vote/ 目录下面)
//巫师可以使用两个指令来设置投票箱,set_exp和set_box
//set_exp 限制不够exp的dummy投票,指令格式为set_exp number

//set_box 分为三步,第一步,系统要求你输入投票的代号,如果这个代号的投票档案存在,
//那么系统会自动载入这个档案,使得此代号的投票活动继续进行!
//如果不存在这个代号的档案,那么继续第二步,输入所有的选项的总个数,
//第三步,输入完整的投票内容,包括所有的选项,推荐格式为:
//
//    本次因为........而投票
//    1. 什么什么...........
//    2. 什么什么............
//    3. 什么什么............
//    4. 什么什么...........
//    ............

#include <ansi.h>
inherit ITEM;
inherit F_SAVE;
int exp=0;
string vote_string="";// 投票完整内容
int choose_number;// 选项数目
int vote_number; //已经投过的票数
string title="temp";// 本次投票活动代号,根据此代号将投票资料存档,便于以后查询

int get_vote_title(string arg,object me);
int get_vote_string(string arg,object me);
int get_choose_number(string arg,object me);

void init()
{
       add_action("do_vote","choose");
       add_action("do_set_box","set_box");
//     add_action("do_check_result","check_result");
       add_action("do_look","look");
       add_action("do_set_exp","set_exp");
}

int do_set_exp(string arg)
{
       int i;
       if (!arg || sscanf(arg,"%d",i)!=1) return notify_fail("正确使用格式应该是set_exp number!\n");
       exp=i;
       this_object()->set("vote_exp",exp);
       this_object()->save();
       write("能参加本次投票的玩家所需要的武学和道行的总和修改为--必须超过"+HIR+exp+NOR+".\n");
       return 1;
}

void create()
{
        set_name( HIW"西游记2006"+HIR"投票箱"NOR, ({ "vote box"}) );
        set_weight(9999999);
        set("unit", "个");
        set("no_clean_up",1);
        set("long",HIM"为了西游记2006更好的发展，请投下您宝贵的一票，谢谢！"NOR);
        setup();
}

int clean_up()
{
    return 0;
}

string query_save_file()
{
        return "/data/vote/vote"+title+".o";
}


int do_set_box()
{
        object me=this_player();
        if (!wizardp(me))
        {
                tell_object(me,"对不起，只有巫师才可以使用此命令！\n");
                return 1;
        }
        tell_object(me,"请设置好本次投票的标题,(如果此标题的投票档案存在,将直接载入votebox)\n");
        input_to( (:get_vote_title:),me);
        return 1;
}
int get_vote_title(string arg,object me)
{
        if (arg=="")
        {
           tell_object(me,"好的,取消此次操作!\n");
           return 1;
        }
        title=arg;
        if (this_object()->restore())
        {
                tell_object(me,"标题为"+HIR+title+NOR"的投票档案被成功载入!\n");
                return 1;
        }
        vote_string="";
        this_object()->set("vote_string","");
        tell_object(me,"请输入本次投票的选项数目:(如果有四个投票项,请输入'4')\n");
        input_to( (:get_choose_number:) ,me);

        return 1;
}

int get_choose_number(string arg,object me)
{
        int i;
        if (arg=="")
        {
                write("请输入正确的数字!\n");
                return 1;
        }
        if (sscanf(arg,"%d",i)!=1)
        {
                write("请输入正确的数字!\n");
                return 1;
        }
        choose_number=i;
        tell_object(me,"请设置好本次投票的内容:(只输入回车取消本次设置,输入'.'表示信息输入完毕。)\n");
        this_object()->set("vote_title",title);
        this_object()->set("choose_number",choose_number);
        input_to ( (:get_vote_string:) ,me);
        return 1;
}

int get_vote_string(string arg,object me)
{
        if (arg=="") return notify_fail(":(!本次投票内容设置取消!\n");

        if (arg=="." && vote_string!="")
         {
           this_object()->set("vote_string",vote_string);
           if (this_object()->save())
              tell_object(me,"ok!设置投票内容完毕，同时已经储存在/data/vote/vote"+HIR+title+NOR".o\n");
           else
              write("糟糕,投票内容无法存档,请自行查找出错原因.\n");
           return 1;
         }
        vote_string+=arg+"\n";
        input_to( (:get_vote_string:) ,me);
        return 1;
}
int do_look(string arg)
{
        int i;
        object ob=this_object();
        choose_number=ob->query("choose_number");
        if (!arg || arg !="vote box") return 0;
        write(HIW"西游记2006"HIR"投票箱"HIW",(请用choose 1|2|3..来投票,谢谢你支持西游记2006的发展!)\n"NOR);
        write(HIG"=========================================================================\n"NOR);
        if (!ob->query("vote_string") || !ob->query("choose_number"))
        {
                write(HIR"西游记2006暂时没有投票活动!\n"NOR);
                return 1;
        }
        write(HIY"本次投票内容\n"NOR);
        write(HIW+ob->query("vote_string")+NOR+"\n");
        write(HIY+"投票对象"+NOR+"\n");
        write(HIW+"道行和武学的总和超过"+HIR+ob->query("vote_exp")+HIW+"的所有玩家!\n\n"NOR);
        write(HIY+"目前投票结果\n"NOR);
        write(HIW+"目前已有"+HIR+ob->query("vote_number")+HIW"位玩家投过票,其中:\n"+NOR);
        for (i=1;i<=choose_number;i++)
          write(HIW+"选"+HIR+i+HIW"的玩家有"+HIR+ob->query(""+i+"/number")+HIW+"位\n"+NOR);
        return 1;
}
int do_vote(string arg)
{
        int i;
        object ob=this_object();
        object me=this_player();
        string *arr;
        choose_number=ob->query("choose_number");
        if (!ob->query("vote_string") || !ob->query("choose_number"))
        {
                write(HIR"西游记2006暂时没有投票活动!\n"NOR);
                return 1;
        }
        if (!arg || sscanf(arg,"%d",i)!=1)
        {
                write(HIW"正确的投票方式是:choose 对应的选项数字 !\n"NOR);
                return 1;
        }
        if (i<1 || i>choose_number)
        {
                write(HIR"没有这个选项!\n"NOR);
                return 1;
        }

        if (arr=ob->query("vote_id") )
          {
            if (member_array(me->query("id"),arr)!=-1 )
              {
                write( HIW"本次活动,你已经投过一票了!\n"NOR);
                return 1;
              }
          }
        if (me->query("daoxing")+me->query("combat_exp")<ob->query("vote_exp") )
          {
            write(HIM"对不起,你的经验值还不够,暂时无法参加投票!\n"NOR);
            return 1;
          }
        ob->add("vote_number",1);
        ob->add(""+i+"/number",1);
        ob->add("vote_id",({me->query("id") }));
        ob->save();
        write_file("/data/vote/vote"+ob->query("vote_title")+".txt",me->query("id")+" vote "+i+"\n");
        write(HIM"本次投票,你选择了选项"+HIR+i+NOR+"\n");
        write(HIM"谢谢您对西游记2006的衷心支持!GOOD LUCK!\n"NOR);
        return 1;
}
