//Cracked by Roath

inherit NPC;

void create()
{
       set_name("老者", ({"lao zhe","old man"}));
       set("long","一个满头白发的老者。\n");
       set("gender", "男性");
       set("age", 66);
       set("combat_exp", 1800);
       set("daoxing", 1800);
        setup();
        carry_object("/obj/loginload/linen")->wear();

}

void init()
{
	object me=this_player();
	object ob=this_object();
	object here;
	add_action("do_agree","agree");
	here= find_object("/d/qujing/huangfeng/indoor");
        here = load_object("/d/qujing/huangfeng/indoor");
	
	if( me->query("obstacle/yz") !="done" 
	|| !(me->query_condition("eyeill")) 
	|| environment(ob)!=here)
	return;
	message_vision("$N看到$n的样子，忙说道：得了眼疾？快随我来！\n",ob,me);		
	message_vision("$N迷迷糊糊的点点头，决定跟随$n行动。\n",me,ob);
	call_out("move_sleeproom",2,me,ob);
}
int move_sleeproom(object me,object ob)
{	object here, where;
	here=environment(me);
	message_vision("$N随着$n向卧室走去。\n",me,ob);
	me->move("/d/qujing/huangfeng/sleeproom");
	me->set_temp("enterroom","yes");
	ob->move("/d/qujing/huangfeng/sleeproom");
	where=environment(me);
	message_vision("$N随着$n走了进来。\n",me,ob);
	call_out("say_sth",2,me,ob);
	return 1;
}
int say_sth(object me,object ob)
{
	message_vision("$N指着草席对$n说道：你在这里休息(sleep)一下，我去取点东西。\n",ob,me);
	message_vision("说完，$N一转身不见了。\n",ob);
	destruct(ob);
	return 1;
}

int do_agree(object me,object ob)
{
	me=this_player();	
	ob=this_object();
	if(me->query_temp("lingjiask")!="yes")
	return 0;
	message_vision("$N低头唱喏道：愿求些儿点试试。\n",me);
	call_out("start_doit",1,me,ob);
	return 1;
}
int start_doit(object me,object ob)
{
	message_vision("$N随即取出一个玛瑙石的小罐儿来，拔开塞口，用玉簪儿蘸出少许，"+
		"与$n点上。\n",ob,me);
        me->apply_condition("eyeill", 0);
        me->receive_curing("kee", 50);
        me->receive_heal("kee", 50);
	me->set_temp("need_sleep","yes");
	call_out("done_it",1,me,ob);
	return 1;
}
int done_it(object me,object ob)
{
	object where;
	message_vision("$N对$n说：安心睡一觉，明早就好。\n说完，转身走了。\n",ob,me);
	
	where= find_object("/d/qujing/huangfeng/indoor");
        where= load_object("/d/qujing/huangfeng/indoor");
	ob->move(where);
	me->start_busy(2);
	call_out("me_sleep_",1,me);

	return 1;
}

int me_sleep_(object me)
{	
	message_vision("$N合上眼睛，安心休息了。\n",me);	
	call_out("me_sleep",1,me);
	return 1;
}
int me_sleep(object me)
{	object dan;
	dan=new("/d/qujing/huangfeng/obj/dingfeng");
	me->set("last_sleep",time()-270);
        me->interrupt_me();
        me->command_function("sleep"); 
	me->move("/d/qujing/huangfeng/shanlu1");
	me->set_temp("lingji1_done","yes");
	dan->move(me);
	return 1;
}




	





