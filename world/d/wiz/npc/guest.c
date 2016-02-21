// mon 1/29/98

inherit NPC_SAVE;

mapping list=([]);
// notified is set as static so that it will not
// be saved or restored.
static string *notified=({});

int do_help(string arg);
void clear_enter(string id);
void allow_enter(string id);
int remain_time(int approve);
void inform_wiz (object who);
int do_clear(string arg);
int do_list();
int do_approve (string arg);
void relay_channel(object ob, string channel, string msg);


void create()
{
        set_name("仙童", ({ "xian tong","tong" }));
        set("long", "");
        set("gender", "男性");
        set("age", 15);
        set("attitude", "friendly");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("per" ,20);
        set("combat_exp", 500000);

        setup();
        carry_object("/d/obj/cloth/xianpao")->wear();
	
	if( clonep() ) CHANNEL_D->register_relay_channel("sys");
	
	reload("guest_room");
}

void init()
{       
        object ob=this_player();
	string id=ob->query("id");
	object me=this_object();
	mapping new_guest;
	int approve;
	
        ::init();
        
	if(!userp(ob)) return;

        if(wizardp(ob)) {
          add_action("do_approve","approve");
          add_action("do_clear","decline");
          add_action("do_list","list");
          add_action("do_help","help");
          call_out ("inform_wiz",1,ob);
        } else {
          approve=ob->query("banned_approved");

          if(!approve) { //first time enter here.
            approve=time(); //current time.
            if(approve<100) approve=-1;
            //this should not happen, but if happened due to
            //incorrect system clock, then set to -1.
            ob->set("banned_approved",approve);
            ob->set("startroom","/d/wiz/guest");
            ob->save();
          }
          
          if(remain_time(approve)==0) {
            allow_enter(id);
            return; 
          }   
          
          write(ob->query("name")+
            "，请等候巫师批准您进入西游记世界！\n");
            
          if(approve>0)  
            write("如果没有巫师在线，您将在"+
              chinese_number(remain_time(approve))+
              "小时后自动获得许可。\n");  
              
          write("请耐心等候，谢谢！\n");
             
          if(approve==-1) return;
          
          if(undefinedp(list[id])) {    
            //add this player to list.
            new_guest=(["name":ob->query("name"),
                        "ip":query_ip_name(ob),
                        "time":approve,
                        ]);
            if(list)
              list+=([id:new_guest]);
            else
              list=([id:new_guest]);
              
            notified=({});
            me->save();                              
          }
         
        }
}

int do_help(string arg)
{
  if(arg) return 0;
  
  write("\n");
  write("你可以在这里处理由banned_sites连线玩家的进入请求，不\n");
  write("管玩家目前正在迎客厅或已经退出均可以。如果不作处理，\n");
  write("则该玩家将在四十八小时后自动获准进入游戏。\n\n");
  write("approve id      准许指定玩家进入游戏。(即使不在list\n");
  write("                中也可以)\n");
  write("approve -all    准许所有申请中玩家进入游戏。\n");
  write("decline id      不准指定玩家进入游戏。如果该玩家是\n");
  write("                newbie，将可能被purge；否则将被禁\n");
  write("                闭于迎客厅，直到有巫师approve为止。\n");
  write("decline -all    同上，不准所有申请中玩家进入游戏。\n");
  write("list            列出所有正在申请中的玩家。\n");
  write("\n");
  return 1;
}

//clear one player enter xyj.
void clear_enter(string id)
{
  object me=this_object();
  object who;
  int online,objp=wizardp(this_player());
   
    who=find_player(id);
    if(who) { //player online now.
      if(!present(who)) {
        if(objp) write(id+"目前不在迎客厅。\n");
        return;
      }  
      online=1;
    } else { //player not online now.     
      who=new(USER_OB);
      who->set("id",id);
      if(!who->restore()) {
        if(objp) write("没有"+id+"这个玩家或文件出错。\n");
	destruct(who);

  if(!undefinedp(list[id])) {
    map_delete(list,id);
    me->save();
  } 
        return;
      }  
      online=0;
    }
  
  if(who->query("banned_approved")!=0) {
    who->set("banned_approved",-1);
    who->save(1);
    if(objp)
      tell_object(this_player(),"您不批准"+who->query("name")+"进入西游记世界！\n");
    if(objp)
      log_file("banned_approve","["+ctime(time())+"]"+
        this_player()->query("id")+" declines "+who->query("id")+
	" to enter.\n");
    else
      log_file("banned_approve","["+ctime(time())+"]"+
        who->query("id")+
	" is declined to enter.\n");
	
  } else {
    if(objp) write("玩家"+id+"不在待批准之列。\n");
  }    
  
  if(online==1) {
  } else {
    destruct(who);
  } 
  
  if(!undefinedp(list[id])) {
    map_delete(list,id);
    me->save();
  } 
}

//allow one player enter xyj.
void allow_enter(string id)
{
  object me=this_object();
  object who;
  int online,objp=wizardp(this_player());
   
    who=find_player(id);
    if(who) { //player online now.
      if(!present(who)) {
        if(objp) write(id+"现在不在迎客厅。\n");
        return;
      }  
      online=1;
    } else { //player not online now.     
      who=new(USER_OB);
      who->set("id",id);
      if(!who->restore()) {
        if(objp) write("没有"+id+"这个玩家或文件出错。\n");
	destruct(who);

  if(!undefinedp(list[id])) {
    map_delete(list,id);
    me->save();
  } 
        return;
      }  
      online=0;
    }
   
  if(who->query("banned_approved")!=0) {
    who->set("banned_approved",1);
    who->set("startroom","/d/city/kezhan");
    who->save(1);
    if(objp)
      tell_object (this_player(),"您批准"+who->query("name")+"进入西游记世界！\n");
    if(objp)
      log_file("banned_approve","["+ctime(time())+"]"+
        this_player()->query("id")+" allows "+who->query("id")+
	" to enter.\n");
    else
      log_file("banned_approve","["+ctime(time())+"]"+
        who->query("id")+
	" is allowed to enter.\n");
  } else {
    if(objp) write("玩家"+id+"不在待批准之列。\n");
  }    
  
  if(online==1) {
    who->move("/d/city/kezhan");
    tell_object (who,"欢迎您进入西游记世界！\n");
  } else {
    destruct(who);
  } 
  
  if(!undefinedp(list[id])) {
    map_delete(list,id);
    me->save();
  } 
}

int remain_time(int approve)
{ 
  int hour=48-(time()-approve)/3600;

  if(approve<0) //i.e., approve==-1
    return approve;  //not auto approve.
  else if(approve==1 || approve==0 || hour<=0)
    return 0; //approved.
  else
    return hour;  //remaining hours to get auto permission.
}  

void inform_wiz (object who)
{
  tell_object (who,who->query("name")+
    "，你可以使用help来查看可用指令。\n");
}

//do not auto permission entry of a player.
//this player must be later explicitly "approved" to enter.
int do_clear(string arg)
{
  object who;
  object me = this_player();
  object where = this_object ();
  string *key;
  int size, i;

  if (!arg)
    return notify_fail ("不批准谁？\n");
    
  if(arg=="-all") { //decline all pending players.
    key=keys(list);
    size=sizeof(key);
    if(size>0) {
      for(i=0;i<size;i++)
        clear_enter(key[i]); 
    }
  } else {  //decline only one player. 
    if (arg == me->query("id")) {
      write("不批准您自己？\n");
      return 1;
    }
    clear_enter(arg);
  }
  
  return 1;
}

//list all pending players in memory.
int do_list()
{
   int i, size;
   string *key;
   
   key=keys(list);
   size=sizeof(key);
   if(size>0) {
     write("等待批准进入游戏的玩家有：\n");
     for(i=0;i<size;i++) {
       int j=remain_time(list[key[i]]["time"]);
       
       write(list[key[i]]["name"]+"("+
         key[i]+")由"+
         list[key[i]]["ip"]+
         "连线，");
       if(j>0)
         write("将于"+j+"小时后自动获准进入游戏。\n");
       else if(j==0) {//should not happen.           
         write("自动获准进入游戏。\n");
         allow_enter(key[i]);
       } else //j<0
         write("必须经巫师批准才能进入游戏。\n");
     }
   } else
     write("目前没有等待批准进入游戏的玩家。\n");
     
   return 1;
}

int do_approve (string arg)
{
  object who;
  object me = this_player();
  object where = this_object ();
  string *key;
  int size, i;

  if (!arg)
    return notify_fail ("批准谁？\n");
    
  if(arg=="-all") { //allow all pending players.
    key=keys(list);
    size=sizeof(key);
    if(size>0) {
      for(i=0;i<size;i++)
        allow_enter(key[i]); 
    }
  } else {  //allow only one player. 
    if (arg == me->query("id")) {
      write("批准您自己？\n");
      return 1;
    }
    allow_enter(arg);
  }
  
  return 1;
}

void relay_channel(object ob, string channel, string msg)
{
	string id, wizid;
	object wiz;
	int size;

        size=sizeof(list);
        if(!size) return;
        
	if( !ob || (channel != "sys") ) return;
	
	id=ob->query("id");
	if(id!="logind") return;

	// Don't process our own speech.
	if( ob==this_object() ) return;
	
	if(sscanf(msg,"%*s(%s)由%*s连线进入。",wizid)!=3) return;
	
	wizid=lower_case(wizid);
	if(!(wiz=find_player(wizid))) return;
	if(!wizardp(wiz)) return;
	
	if(member_array(wizid,notified)==-1) { //not notified yet.
	  //notify login wiz about pending players in the guest room.
	  tell_object(wiz,"现在有"+chinese_number(size)+
	    "位玩家在迎客厅等候批准，请您处理。(/d/wiz/guest)\n");
          notified+=({wizid});
        } //each wiz will only be notified once.
}

