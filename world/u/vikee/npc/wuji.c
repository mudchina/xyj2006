//wuji.c  writted bye beeby . 2000.6.28

inherit NPC;

void create()
{
       set_name("长孙无忌", ({"zhangsun wuji","wuji"}));
       set("gender", "男性");
	set("title","户部尚书");
       set("age", 55);
       set("str", 25);
	set("int",30);
       set("attitude", "friendly");
        set("combat_exp", 30000);
	set("daoxing", 50000);

        set("attitude", "friendly");
        set("class", "scholar");
        set_skill("unarmed", 50);
        set_skill("dodge",50);
        set_skill("literate", 100);
        set_skill("parry", 50);

        set("force", 500);

       setup();

       carry_object("/d/obj/cloth/choupao")->wear();
       add_money("silver", 1);
}

void init()
{
        object ob;
       
        ::init();
        add_action("do_apply", "apply");
}

int do_apply(string args)
{
   string respect_type,respect_str;
   object me=this_player();
   object mymoney;
   int dx,amount;
   
   if (!args || sscanf(args,"%s to %s",respect_type,respect_str) !=2)
   {
      tell_object(me,"格式为: apply <要申请的类型> to <称呼> \n"+
		     "可以申请的称呼如下: \n"+
                     "  respect       别人对自己的尊称(道行500年,黄金50两)\n"+
//		     "  rude          别人对自己的粗鲁的称呼(道行500年,黄金50两)\n"+
                     "  self          自己对自己的称呼(道行100年,黄金50两)\n"+
                     "  self_rude     自己对自己粗鲁的称呼(道行100年,黄金50两)\n"+
                     "又：请勿使用不恰当的称谓。不然称呼被取消，五十两\n"+
                     "金子就白白扔了。至于恰当与否，则由天上神仙决定。\n");

      return 1;
   }
   else 
   {
        mymoney=present("gold_money",me);
	if (!mymoney)
         {
	    command("heng");
            return notify_fail("长孙无忌说道:你没钱跑来凑什么热闹?\n");
         }
	switch (respect_type)
 	{
          case "respect":
//        case "rude":
            {
		dx=500000;
		amount=50;
		break;
	    }
	  case "self" :
	  case "self_rude":
	    {
		dx=100000;
		amount=50;
		break;
	    }
	  default:
	     return notify_fail("你要申请那种称呼?\n");
	}
	if (me->query("daoxing") < dx)
           return notify_fail("你的道行不够. \n");
	if (mymoney->query_amount() < amount)
           return notify_fail("你的金子不够. \n");
           me->set("rank_info/"+respect_type,respect_str);
	     if (mymoney->query_amount() == amount)
               destruct(mymoney);
             else
               mymoney->add_amount(-amount);
          }
	message_vision("长孙无忌点了点头, 提起笔在一个簿子上改了几笔.\n",me);
	return 1;

}
