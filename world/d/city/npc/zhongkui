#include <ansi.h>
#define LIMIT_LENGTH    30
inherit NPC;
string replace_long(string long);
void random_place(object who,object seal);
mapping *wheres=({
      (["chinese":                "祭赛国",
       "weizhi" :              "/d/qujing/jisaiguo",]), 
 (["chinese":                "长安城外",
        "weizhi" :              "/d/changan",]), 
  (["chinese":                "长安城东",
       "weizhi" :              "/d/eastway",]), 
  (["chinese":                "高老庄",
       "weizhi" :              "/d/gao",]), 
  (["chinese":                "开封城",
       "weizhi" :              "/d/kaifeng",]), 
  (["chinese":                "方寸山",
       "weizhi" :              "/d/lingtai",]), 
  (["chinese":                "月宫",
       "weizhi" :              "/d/moon",]), 
  (["chinese":                "普陀山",
       "weizhi" :              "/d/nanhai",]), 
  (["chinese":                "龙宫",
       "weizhi" :              "/d/sea",]), 
  (["chinese":                "长安城西",
       "weizhi" :              "/d/westway",]), 
  (["chinese":                "五庄观",
       "weizhi" :              "/d/qujing/wuzhuang",]), 
  (["chinese":                "红楼一梦",
       "weizhi" :              "/d/ourhome/honglou",]), 
  (["chinese":                "地府",
       "weizhi" :              "/d/death",]), 
  (["chinese":                "蓬莱仙岛",
       "weizhi" :              "/d/penglai",]), 
  (["chinese":                "大雪山",
       "weizhi" :              "/d/xueshan",]), 
  (["chinese":                "豹头山",
       "weizhi" :              "/d/qujing/baotou",]), 
      (["chinese":                "乌鸡国",
       "weizhi" :              "/d/qujing/wuji",]), 
      (["chinese":                "车迟国",
       "weizhi" :              "/d/qujing/chechi",]), 
      (["chinese":                "宝象国",
       "weizhi" :              "/d/qujing/baoxiang",]), 
      (["chinese":                "比丘国",
       "weizhi" :              "/d/qujing/biqiu",]), 
      (["chinese":                "东土大唐",
       "weizhi" :              "/d/city",]), 
      (["chinese":                "凤仙郡",
       "weizhi" :              "/d/qujing/fengxian",]), 
      (["chinese":                "金平府",
       "weizhi" :              "/d/qujing/jinping",]), 
      (["chinese":                "女儿国",
       "weizhi" :              "/d/qujing/nuerguo",]), 
       (["chinese":                "钦法国",
       "weizhi" :              "/d/qujing/qinfa",]), 
       (["chinese":                "天竺国",
       "weizhi" :              "/d/qujing/tianzhu",]), 
       (["chinese":                "玉华县",
       "weizhi" :              "/d/qujing/yuhua",]), 
       (["chinese":                "天竺国",
       "weizhi" :              "/d/qujing/tianzhu",]), 
       (["chinese":                "朱紫国",
       "weizhi" :              "/d/qujing/zhuzi",]), 
      });

      void create()
{
        set_name("钟馗", ({"zhong kui", "zhongkui", "kui"}));
        set("title", WHT"鬼见愁"NOR);
        set("gender", "男性" );
        set("age", 30);
    set("per", 100);
 set("long", "上天入地无所不能的抓鬼大仙，你在这里可以降妖(xiangyao)。\n");

        set("class", "taoist");
        set("combat_exp", 3000000);
        set("attitude", "peaceful");
        set_skill("unarmed", 250);
        set_skill("dodge", 250);
        set_skill("parry", 250);
        set_skill("blade", 250);
        set_skill("force", 250);   
        set_skill("literate", 280);
        set_skill("spells", 250);
        set("max_kee", 1500);
        set("max_sen", 1400);
        set("force", 4000);
        set("max_force", 2400);
        set("mana", 6000);
        set("max_mana", 3000);   
        set("force_factor", 120);
        set("mana_factor", 150);
          setup();
                carry_object("/d/lingtai/obj/xiangpao")->wear();

}
void init()
{
    add_action("do_quest", "xiangyao");
}
int do_quest()
{
	object who, seal;
	mapping room;
	
	who=this_player();
	message_vision("$N诚心诚意地对$n说：“弟子愿意前去降妖除魔！”\n",who,this_object());
	if((time()-who->query("catch_ghost/last_time"))<300)
	{
		command("say 现在还算比较太平，你先去歇了吧。");
		return 1;
	}
	seal=new("/d/g_quest/obj/seal");
	seal->set("master", who);
        random_place(who,seal);
        command("nod");
	message_vision("$N对$n说道：这张符给你，你看看符上写的符号去抓鬼吧。\n", 
	this_object(), who);
	return 1;
}

int accept_object(object who, object ob)
{
	int reward, times;
	string msg;
	
	if(!ob->query("finished")||
		who!=ob->query("master"))
		return 0;
	command("nod");
	message_vision("$N对$n说道：很好！\n", this_object(), who);
	times=who->query_temp("catch_ghost");
	reward=800+random(200)*times+200*times;
	msg="被奖励了";
	switch(random(3))
	{
		case 0:
			who->add("wuxue_exp", reward);
			who->add("catch_ghost/cache/wuxue", reward);
			msg+=chinese_number(reward)+"点武学。\n";
			break;
		case 1:
			who->add("combat_exp", reward);
			who->add("catch_ghost/cache/dx", reward);
			msg+=COMBAT_D->chinese_daoxing(reward)+"道行。\n";
			break;
		default:
			who->add("potential", reward/4);
			who->add("catch_ghost/cache/pot", reward/4);
			msg+=chinese_number(reward/4)+"点潜能。\n";
	}
	who->add_temp("catch_ghost", 1);
	if(who->query_temp("catch_ghost")>9)
		who->set_temp("catch_ghost", 0);
        MONITOR_D->report_system_object_msg(who, "[抓鬼]"+msg);
        tell_object(who, "你"+msg);
        return 1;
}
void random_place(object who,object seal)
{
        int  fs,k;
        mixed*  file;
        object newob;
        string dirs;
        k=random(sizeof(wheres));
        dirs=wheres[k]["weizhi"];
        seal->set("where",wheres[k]["chinese"]);
        file = get_dir( dirs+"/*.c", -1 );
        if( !sizeof(file) )  return;
        for(k=0;k<5;k++)
         {
           fs = random(sizeof(file));
           if( file[fs][1] > 0 )
             {
              dirs+="/"+file[fs][0];
              newob=load_object(dirs);
                 if (newob)
                  {  
                   seal->set("file_name", dirs);
	           seal->set("desc",replace_long(newob->query("long")) );
	           seal->move(who);
	           who->set("catch_ghost/last_time", time()); 
        	  }
	     }
	}
}
string replace_long(string long)
{
	string tmp="", target="";
	int length, start, i;
	int blank_flag=0;
	
	long=replace_string(long, "\n", "");
	for(i=0;i<strlen(long);i++)
		if(long[i]>160 && long[i]<255)
			tmp+=long[i..i];
	length=strlen(tmp);
	if(length<LIMIT_LENGTH*2)
		return "";
	start=random(length-LIMIT_LENGTH);
	if(start%2)
		start--;
	length=0;
	for(i=start;i<start+LIMIT_LENGTH;i+=2)
	{
		if(blank_flag<-random(2)-2)
		{
			target+="■";
			length++;
			if(random(2) || length>2)
			{
				blank_flag=0;
				length=0;
			}
		}
		else
		{
			blank_flag--;
			target+=tmp[i..i+1];
		}
	}
	return target;
}
