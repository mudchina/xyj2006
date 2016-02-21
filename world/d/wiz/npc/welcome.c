
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

// worker.c

inherit NPC;
#include <ansi.h>

string *msg = ({
// "新手多多help，如help news,help qj，help renwu！\n",
//             "西游记2006主页地址是 http://dtxy.126.com,欢迎访问！\n",
//       "help news里面有关于MUD的最新变化！\n",
//          "help rulaitask是取经之后的任务系统！\n",
//          "help zongshi里面介绍西游记2006各大门派宗师！\n",
//  "help newpfm里面有部分大唐特色perform的介绍！\n",
//"西游记2006主页提供在线查询功能（仅限安徽站），欢迎访问！\n",
//"请用top指令来查询目前在线玩家的排行，以及用topten指令来查看总排行\n",
//"西游记2006新增加一任务系统---炼丹，请help liandan查看详细信息。\n",
      "大唐论坛新增－－『 新站宣传版 』 ，http://bbs.94boy.com\n",
"请到客栈楼上 用 ask bai about gift　来索取春节礼物。\n",
"大家记的随时备份自已的档案，备份指令是：backup\n",
        });

void create()
{
        set_name("西游记2006", ({"DTXY"}));
        set("gender", "男性" );
        set("age", 13);
        set("title", "西游记2006新闻发布使");
        set("long", "一个可爱的小童，每天负责在这里迎接远道而来的客人．\n");
        set("combat_exp", 200);
        set("attitude", "friendly");
        set_skill("dodge", 10);
        set("per", 30);
        set("max_kee", 1500000);
        set("kee",1500000);
        set("sen",1500000);
        set("max_sen", 1500000);
        setup();
        remove_call_out("msg");
        call_out("msg",60);
}

void msg()
{
        command_function("es "+NOR+HBRED+msg[random(sizeof(msg))]+NOR);
        
        remove_call_out("msg");
        call_out("msg",300);

}

