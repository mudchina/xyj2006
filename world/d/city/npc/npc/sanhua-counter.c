//Cracked by Roath
// mon@xyj 8/7/99

inherit NPC_SAVE;

mapping list=([]);
int last_time;
void check_date();

void create()
{
        reload("city_sanhua");
        set_name("打手", ({"da shou", "shou"}));
        set("age", 22);
        set("gender", "男性");
        set("long",
"三花堂的小喽罗，虽然武功不怎么样，但心黑手辣，也不好惹。\n");
        set("attitude", "heroism");

        set("combat_exp", 10000+random(2000));

        set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("blade", 20);
	set("str",200);

        setup();
        carry_object("/d/obj/weapon/blade/blade")->wield();
        carry_object("/d/obj/cloth/linen")->wear();
}

void init()
{
    int t;

    ::init();
    
    if(userp(this_player())) {
	add_action("do_pay","pay");
	add_action("do_list","list");
	add_action("do_drop","drop");

	
	t=time();
	if(!last_time) {
	    last_time=t;
	    check_date();
	    save();
	} else if(t<last_time) {
	    last_time=t;
	    save();
	} else if((t-last_time)>43200) {
	    last_time=t;
	    check_date();
	    save();
	}
    }
}

void check_date()
{
    int i, t, t1, amount;
    string *key;

    reset_eval_cost();
    i=sizeof(list);
    if(i) key=keys(list);
    else return;
    
    t=time();
    while(i--) {
	t1=list[key[i]]["last_time"];
	if(t<t1) {
	    list[key[i]]["last_time"]=t;
	} else if((t-t1)>604800) {
	    amount=list[key[i]]["amount"];
	    amount=amount*7/10;
	    if(amount<1) {
		map_delete(list, key[i]);
	    } else {
		list[key[i]]["amount"]=amount;
	        list[key[i]]["last_time"]=t;
	    }
	}
    }
    save();
}

int do_pay(string arg)
{
    object me, who;
    int amount, online;
    string id;

    me=this_player();

    if(!arg) return notify_fail("Usage: pay <amount> gold for <id>\n");

    if(sscanf(arg, "%d gold for %s", amount, id)!=2) 
	return notify_fail("你要悬赏多少黄金去杀谁？\n");
    
    if(amount<1) return notify_fail("需要至少一两黄金。\n");
    if(amount>1000) return notify_fail("一次最多一千两黄金。\n");
    
    if(me->query("balance")<(amount*10000))
	return notify_fail("你的帐户里没有这么多钱。\n");

    if(wizardp(me))
	return notify_fail("这个．．．怕不太好吧？：）\n");

    notify_fail("你要悬赏去杀谁？\n");
    
    if(!id || sizeof(id)<1) return 0;
    id=replace_string(id,"#"," ");
    id=replace_string(id,"."," ");
    
    who=find_player(id);
    if(!who) { //player not online now.
	seteuid(geteuid(me));
	who=new(USER_OB);
	who->set("id",id);
	if(!who->restore()) {
	    if(who) destruct(who);
	    if(!undefinedp(list[id])) { // suicided already
		map_delete(list, id);
		save();
	    }
	    return notify_fail("找不到 "+id+" 这个人。\n");
	}
	online=0;
    } else {
	online=1;
    }

    if(SECURITY_D->get_wiz_level(who)>0) {
	if(!online) destruct(who);
	return notify_fail("这个．．．怕不太好吧？：）\n");
    }

    if(online && amount>=50) {
	tell_object(who,"你心中忽然升起一种异样的感觉。\n");
    }

    if(undefinedp(list[id])) {
	if(sizeof(list)>2000) {
	    if(!online) destruct(who);
	    return notify_fail("被悬赏追缉的玩家数太多了。\n");
	}

	list[id]=(["amount": amount,
		   "last_time": time(),
		   "name":who->query("name")+"("+
		       capitalize(id)+")",
		   ]);
    } else {
	list[id]=(["amount": amount+list[id]["amount"],
		   "last_time": time(),
		   "name":who->query("name")+"("+
		       capitalize(id)+")",
		   ]);
    }
    
    me->add("balance",-amount*10000);
    me->save();

    save();
    
    message_vision("$N出"+chinese_number(amount)+
	    "两黄金悬赏"+who->query("name")+
	    "("+id+")头颅，目前总赏金"+
	    chinese_number(list[id]["amount"])+
	    "两。\n", me);
    
    log_file("sanhua","["+ctime(time())+"] "+
	    me->query("id")+" paid "+amount+" gold for "+
	    id+".\n");
    if(!online) destruct(who);

    return 1;
}

string get_time(int last)
{
    int day;
    string result;

    if(!last) last=time();
    last=time()-last;
    if(last<0) last=0;
    
    last/=3600;
    day=last/24;
    last=last%24;
    if(day) result=chinese_number(day)+"天";
    else result="";
    
    result+=chinese_number(last)+"小时";
    return result;
}
int do_list(string arg)
{

    int i;
    string format, result, *key;
    string *sort=({});

    i=sizeof(list);
    if(i<1) return notify_fail(
	    "目前没有人被追杀。\n");

    format="　%-24s%20s%20s\n";

    result="\n"+sprintf(format,"　　名　字","赏　金",
	    "距上次增加赏金")+
 "────────────────────────────────────\n";


    if(!arg) {
        key=keys(list);
	while(i--) {
	    sort+=({sprintf("%6d",list[key[i]]["amount"])
		    +"|"+
		    sprintf(format,list[key[i]]["name"],
		    chinese_number(list[key[i]]["amount"])+"两",
		    get_time(list[key[i]]["last_time"]))});
	}
	if(i=sizeof(sort)) {
	    sort=sort_array(sort,1);
	    while(i--) {
		result+=sort[i][strsrch(sort[i],"|")+1..];
	    }
	}
    } else {
	if(undefinedp(list[arg])) return
	    notify_fail("没有人悬赏追杀 "+arg+"。\n");

	result+=sprintf(format,list[arg]["name"],
		chinese_number(list[arg]["amount"])+"两",
		get_time(list[arg]["last_time"]));
    }
    result+=
 "────────────────────────────────────\n";

    this_player()->start_more(result);
    return 1;
}

int do_drop(string arg)
{
    object me, ob;
    string id;

    me=this_player();

    if(!arg) return 0;

    if(!(ob=present(arg,me))) return 0;

    if(!ob->is_corpse()) return 0;
    
    if(!ob->query("is_player")) return 0;
    
    id=ob->query("victim_id");
    if(!id) return 0;
    
    if(undefinedp(list[id]))  return 0;
    
    message_vision("$N将身上背着的尸首往地上一摔，"+
	    "$n急忙趋前细看，不禁面露喜色。\n",me,this_object());
    message_vision("$N对$n小声嘀咕道：可真有你的，居然把"+
	    list[id]["name"]+"给弄死了！这"+
	    chinese_number(list[id]["amount"])+
	    "两金子小的就帮您存钱庄啦！\n\n",this_object(),me);

    me->add("balance",10000*list[id]["amount"]);
    log_file("sanhua","["+ctime(time())+"] "+me->query("id")
	    +" is paid "+list[id]["amount"]+" gold for "
	    +list[id]["name"]+"'s corpse.\n");

    map_delete(list, id);
    save();
    destruct(ob);
    
    return 1;
}
