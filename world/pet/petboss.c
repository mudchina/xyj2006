// rewritten by vikee 
// 2000.11
// 还差pet 属性
inherit NPC;

#include <ansi.h>
#include <login.h>
int  do_sm();
int  do_dispose(string arg);
int  do_upgrade(string arg);
int  do_list();
int  do_cost(string arg);

void get_type(string arg, object ob);
void get_subtype(string arg, object ob);
void get_gender(string arg,object ob);
void get_id(string arg, object ob);
void get_name(string arg, object ob);
void get_desc(string arg, object ob);
void get_unit(string arg, object ob);
void build_pet(object ob);
int check_legal_name(string name, int max_len);
int check_legal_id(string name);
void confirm_dispose(string arg, object ob, object fabao_ob);

string* pet_type_name=({
        "鼠","牛","虎","兔","龙","蛇",
        "马","羊","猴","鸡","狗","猪",
        "猫","熊","狮","狼","豹","狐",
        "貂","鸟","虫","麒麟","圣灵兽",
	});
string* pet_id_surfix=({
	"shu","niu","hu","tu","long","she",
	"ma","yang","hou","ji","gou","zhu",
	"mao","xiong","shi","lang","bao","hu",
	"diao","niao","chong","qilin","shengling shou",
	});
string* pet_unit_name=({
	"只","头","头","只","条","条",
	"匹","头","头","只","条","头",
	"只","头","头","头","匹","只",
	"只","只","条","头","头",
	});
void create()
{
  set_name("老板", ({"boss"}));
  set("title","宠物店老板");
  set("gender", "男性");
  set("age", 32);
  set("long","一个身着朴素的老板。\n");
  set("attitude", "peaceful");
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
  add_money("coin", 100);

}

void init()
{
  object ob;

  ::init();
  add_action("do_sm", "choose");
  add_action("do_dispose", "dispose");
  add_action("do_list", "list");
  add_action("do_cost", "cost");
  add_action("do_upgrade", "upgrade");
  add_action("do_change_name", "change_name");
  add_action("do_change_id", "change_id");
  add_action("do_change_desc", "change_desc");
  add_action("do_change_unit", "change_unit");

}
void accept_kill(object me)
{       object ob;
        if(is_fighting()) return;
        if( query("called") ) return;

        command("help!");

        ob=present("xunluo guanbing");
        if( !ob) {
                seteuid(getuid());
                ob=new("/d/city/npc/xunluobing");
                ob->move(environment());
        }
        message_vision("\n忽然从门外冲进来个巡逻官兵，对$N大喊一声“干什么？想杀人谋财么！\n\n",me);        

        ob->kill_ob(me);
        ob->set_leader(me);
        me->fight_ob(ob);
        set("called", 1);
        call_out("regenerate", 300);
}
int regenerate()
{
        set("called", 0);
        return 1;
}


int do_sm()
{
	object me = this_player();
		   
	if( me->query("combat_exp") < 50000)
		return notify_fail("你的道行太低，自己都怕养不活,不能豢养宠物。\n");
	
	if( me->query("pet")) 
		return notify_fail("你已经养了一头宠物了，请用 dispose 归还你现在的宠物n");
		
	write("您要养哪类宠物：\n");
	write(" 1. 鼠   2. 牛   3. 虎   4. 兔  5. 龙  6. 蛇\n");
	write(" 7. 马   8. 羊   9. 猴  10. 鸡 11. 狗 12. 猪\n");
	write("13. 猫  14. 熊  15. 狮  16. 狼 17. 豹 18. 狐\n");
	write("19. 貂  20. 鸟  21. 虫  22. 麒麟  23 圣灵兽\n");
     	write("请选择：(q 键取消)");
	input_to( (: get_subtype :), me);
	return 1;
}

void get_subtype(string arg, object ob)
{
    int  order;
   object me=this_player();// add for new pet system
	if( arg == "q" || arg == "Q" )    return;

    	sscanf(arg, "%d", order);
        // 宠物级别选择
        if( me->query("combat_exp")/1000000<order)
		{write("你的功夫太低，不能豢养这种宠物。\n");
	          return;}
	//if(me->query_skill("train",1)/10<order)
	 //       {write("你的驯兽功夫恐怕不到家。\n");
	 //         return;}
       // over
	  if (order <= 0 || order > 23)  {
		
	        write("您要养哪类宠物：\n");
        	write(" 1. 鼠   2. 牛   3. 虎   4. 兔  5. 龙  6. 蛇\n");
    	    	write(" 7. 马   8. 羊   9. 猴  10. 鸡 11. 狗 12. 猪\n");
        	write("13. 猫  14. 熊  15. 狮  16. 狼 17. 豹 18. 狐\n");
        	write("19. 貂  20. 鸟  21. 虫  22. 麒麟  23 圣灵兽\n");
        	write("请选择：(q 键取消)");
		input_to( (: get_subtype :), ob);
		return;
	}
	
	ob->set_temp("pet/pet_type",  order);

	write("\n");
	write("请设定宠物的性别(雄性：1  雌性:０)：");
	input_to( (: get_gender :), ob ); 
}

void get_gender(string arg, object ob)
{
	int gender;
        sscanf(arg, "%d", gender);

          if (gender != 0 && gender != 1)  {
        	write("\n");
        	write("请设定宠物的性别(雄性：1  雌性:０)：");
        	input_to( (: get_gender :), ob );
		return;
	    }
	ob->set_temp("pet/pet_gender",gender?"男性":"女性");

        write("\n");
        write("请设定英文 id ：");
        input_to( (: get_id :), ob );
}
int check_legal_id(string id)
{
	int i;
	string	*legalid;
  	object ppl;	
	i = strlen(id);
    if( (strlen(id) < 3) || (strlen(id) > 20 ) ) {
		write("对不起，英文 id 必须是 3 到 20 个英文字母。\n");
		return 0;
    }
    while(i--)
    	if( id[i] != ' ' && (id[i]<'a' || id[i]>'z') )  {
    		write("对不起，英文 id 只能用英文字母。\n");
    		return 0;
    	}

        ppl = LOGIN_D->find_body(id);
        if(ppl || id=="guest" || id=="new") {
            write("这个名字与别的玩家ID相同了．．．");
            return 0;
        }

        if( file_size(sprintf("/data/user/%c/%s",id[0],id)
                    + __SAVE_EXTENSION__) >= 0 ) {
            write("这个名字已经被别的玩家使用了．．．");
	    return 0;
   	} 
    legalid = explode(read_file(BANNED_ID), "\n");
    for(i=0; i<sizeof(legalid); i++)   {
    	if( id == legalid[i] )   {
    		write("对不起，这种 id 会造成其他人的困扰。\n");
    		return 0;
    	}
    }
    
    return 1;
}

int check_legal_name(string name, int max_len)
{
	int i;
	string	*legalname;		//not implemented..may add later
	
	i = strlen(name);
    if( (strlen(name) < 2) || (strlen(name) > max_len ) ) {
    	write( sprintf("对不起，法宝中文字必须是 1 到 %d 个中文字。\n",
    	 max_len/2) );
		return 0;
    }
    while(i--)   {
    	if( name[i]<=' ' )   {
    		write("对不起，法宝中文字不能用控制字元。\n");
    		return 0;
    	}
    	if( i%2==0 && !is_chinese(name[i..<0]) )  {
    		write("对不起，请您用「中文」给法宝取名字。\n");
    		return 0;
    	}
    }
   
    return 1; 
}


void get_id(string arg, object ob)
{
	arg = lower_case(arg);
	if( !check_legal_id(arg) )   {
		write("请设定英文 id ：");
		input_to( (: get_id :), ob ); 
		return;
	}

	arg = replace_string(arg, " ", "_");	
	ob->set_temp("pet/pet_id",arg+" "+
	pet_id_surfix[ob->query_temp("pet/pet_type")-1]);
	
	write("\n");
	write("现在你可以设定中文名，请注意，你设定的中文名会加上基本名。\n");
	write("比如你选择的是兔，中文名为小白, 名字就会为小白兔\n");
	write("请设定中文名：(可加颜色)");
	input_to( (: get_name :), ob);
}

void get_name(string arg, object ob)
{
	string  arg_old;
	
//	arg += "$NOR$";
	arg_old = arg;
        arg = replace_string(arg, "$BLK$", "");
        arg = replace_string(arg, "$RED$", "");
        arg = replace_string(arg, "$GRN$", "");
        arg = replace_string(arg, "$YEL$", "");
        arg = replace_string(arg, "$BLU$", "");
        arg = replace_string(arg, "$MAG$", "");
        arg = replace_string(arg, "$CYN$", "");
        arg = replace_string(arg, "$WHT$", "");
        arg = replace_string(arg, "$HIR$", "");
        arg = replace_string(arg, "$HIG$", "");
        arg = replace_string(arg, "$HIY$", "");
        arg = replace_string(arg, "$HIB$", "");
        arg = replace_string(arg, "$HIM$", "");
        arg = replace_string(arg, "$HIC$", "");
        arg = replace_string(arg, "$HIW$", "");
        arg = replace_string(arg, "$NOR$", "");

	if( !check_legal_name(arg, 12) )  {
        write("现在你可以设定中文名，请注意，你设定的中文名会加上基本名。\n");
        write("比如你选择的是兔，中文名为小白, 名字就会为小白兔\n");
 	    write("请设定中文名：(可加颜色)");
		input_to( (: get_name :), ob);
		return;
	}

	arg = arg_old;

        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);
	
	ob->set_temp("pet/pet_name", arg );
	
	write("\n");
	write("请描述宠物：");
	input_to( (: get_desc :), ob);
}

void get_desc(string arg, object ob)
{
	if( !check_legal_name(arg, 60) )  {
		write("请描述宠物：");
		input_to( (: get_desc :), ob);
		return;
	}

	ob->set_temp("pet/pet_desc",  arg);
	
	write("\n");
	write("宠物用量词：(Return for default)");
	input_to( (: get_unit :), ob);
}


void get_unit(string arg, object ob)
{
	string pet_unit, pet_type;
    if( arg == "" )
       pet_unit = "";
	else if( !check_legal_name(arg, 2) )  {
 	   write("宠物用量词：(Return for defult)");
	   input_to( (: get_unit :), ob);
	   return;
    }
    else
       pet_unit = arg; 
   
	pet_type = ob->query_temp("pet/pet_type");
	ob->set_temp("pet/pet_unit", pet_unit);
	build_pet(ob);	
	// may have more later
}

void build_pet(object ob)
{
	object newob;
	string *id_list, *t_list;
	int rev;
	string msg;
	string pet_type = ob->query_temp("pet/pet_type");
	string pet_id = ob->query_temp("pet/pet_id");
	string pet_name = ob->query_temp("/pet/pet_name");
	string pet_desc = ob->query_temp("pet/pet_desc");
	string pet_unit = ob->query_temp("pet/pet_unit");
 	string base_name= pet_type_name[(int)pet_type - 1];	
	string pet_gender = ob->query_temp("pet/pet_gender");
	newob = new(__DIR__"pet");
	if(!newob)
		return ;
	seteuid(pet_id);
	rev = export_uid(newob);
	seteuid(getuid());

	
	newob->set("weight", 1000);
	
	newob->set("long", pet_desc+"\n"+"它是"+ob->query("name")+

        "的宠物。\n");

	if( pet_unit != "" )
	   newob->set("unit", pet_unit);
	else 
	   newob->set("unit", pet_unit_name[(int)pet_type-1]);
	id_list = ({ pet_id });
	t_list = explode( pet_id, " ");
	if( sizeof(t_list) > 1 )   {
		id_list += t_list;
	}
	pet_name+=base_name+NOR;	
	newob->set_name( pet_name, id_list ); 

	// set owner of pet
	newob->set("owner", ob->query("id"));
	newob->set("series_no", "1");
	newob->set("gender",pet_gender);
	newob->save();
	ob->set("pet/pet_id",pet_id);	
	ob->set("pet/pet_type", base_name);
	ob->set("pet/pet_name", pet_name);
	ob->set("pet/pet_desc", pet_desc);
	ob->set("pet/pet_unit", pet_unit);

	newob->setup();
	msg="$N转身到屋内抱了一只"+pet_name+"出来。\n"+
	    "恭喜$n领养了"+pet_name+"，以后$n可要好好待它。\n";
	message_vision(msg,this_object(),ob);
	if( !newob->move(ob) )
	   newob->move(environment(ob));
	ob->delete_temp("pet");
	ob->save();

	return;
}


int  do_dispose(string arg)
{
   object ob = this_player();
   object pet_ob;
   string pet_id;
    
   if (!ob->query("pet/pet_id"))
      return notify_fail("你并没有宠物，来凑什么热闹？\n");
   pet_id=ob->query("pet/pet_id");
   if( !objectp(pet_ob=present(pet_id, ob)) && 
       !objectp(pet_ob=present(pet_id, environment(ob))))
      return notify_fail("你的宠物没和你一起来吗?\n");
      
   if(pet_ob->query("owner") != ob->query("id")) 
      return notify_fail("这......这个宠物好象不是你的耶！\n");
      
   write("你确定要抛弃你的"+pet_ob->query("name")+"(y/n)");
   if (ob->query_temp("pet")==1)
   {
     ob->set_temp("apply/dodge",0);
     ob->set_temp("pet",0);
   }

     
   input_to( (: confirm_dispose :), ob, pet_ob); 
   return 1;
}

void confirm_dispose(string arg, object ob, object pet_ob)
{
   string msg;

   if( arg == "y" || arg == "Y" )  {
	ob->delete("pet");
	msg="$N哀怨地看了$n一眼，默默地走进了后屋。\n";
	message_vision(msg,pet_ob,ob);
	destruct( pet_ob );
//add by yudian
ob->delete_temp("ride/dodge");
   }

   return;
}



int  do_change_name(string arg)
{
   string name, newname;
   object fabao_ob, me=this_player();
  
   if( !arg || arg == "") 
      return notify_fail("请用 change_name <宠物> <新中文名> 来改名。\n");
      
   if( sscanf(arg, "%s %s", name, newname) != 2)
      return notify_fail("请用 change_name <宠物> <新中文名> 来改名。\n");
   
   if( !objectp(fabao_ob=present(name, me)) )
      return notify_fail("你身上没有这样宠物啊。\n");

   if(!fabao_ob->query("owner_id") || !fabao_ob->query("series_no")) 
      return notify_fail("那个不是你的宠物耶！\n");

   
   newname += "$NOR$";      
   arg = newname;
            
        arg = replace_string(arg, "$BLK$", "");
        arg = replace_string(arg, "$RED$", "");
        arg = replace_string(arg, "$GRN$", "");
        arg = replace_string(arg, "$YEL$", "");
        arg = replace_string(arg, "$BLU$", "");
        arg = replace_string(arg, "$MAG$", "");
        arg = replace_string(arg, "$CYN$", "");
        arg = replace_string(arg, "$WHT$", "");
        arg = replace_string(arg, "$HIR$", "");
        arg = replace_string(arg, "$HIG$", "");
        arg = replace_string(arg, "$HIY$", "");
        arg = replace_string(arg, "$HIB$", "");
        arg = replace_string(arg, "$HIM$", "");
        arg = replace_string(arg, "$HIC$", "");
        arg = replace_string(arg, "$HIW$", "");
        arg = replace_string(arg, "$NOR$", "");
        
   if( !check_legal_name(arg, 12) )   {
      return 1; 
   }
  
   arg = newname;
    
        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);
  
   fabao_ob->set("name", arg);
   fabao_ob->save();     
   
   write("改动成功。\n");
   return 1;
}
      
int  do_change_id(string arg)
{
   string name, newname;
   object fabao_ob, me=this_player();
   string *id_list, *t_list;
  
   if( !arg || arg == "") 
      return notify_fail("请用 change_id <宠物> <新英文名> 来改名。\n");
      
   if( sscanf(arg, "%s %s", name, newname) != 2)
      return notify_fail("请用 change_id <宠物> <新英文名> 来改名。\n");
   
   if( !objectp(fabao_ob=present(name, me)) )
      return notify_fail("你身上没有这样东西啊。\n");

   
   
   if( !check_legal_id( newname ) )		return 1;
  
   newname = replace_string(newname, " ", "_"); 
   fabao_ob->set("id", newname);

   id_list = ({ newname });
   t_list = explode( newname, "_");
   if( sizeof(t_list) > 1 )   {
	  id_list += t_list;
   }
   fabao_ob->set_name( fabao_ob->query("name"), id_list ); 
   fabao_ob->save();
	
   write("改动成功。\n");
   return 1;
}

      
int  do_change_desc(string arg)
{
   string name, newname;
   object fabao_ob, me=this_player();
  
   if( !arg || arg == "") 
      return notify_fail("请用 change_desc <宠物> <新描述> 来重新描述宠物。\n");
      
   if( sscanf(arg, "%s %s", name, newname) != 2)
      return notify_fail("请用 change_desc <宠物> <新描述> 来重新描述宠物。\n");
   
   if( !objectp(fabao_ob=present(name, me)) )
      return notify_fail("你身上没有这样东西啊。\n");

   if(!fabao_ob->query("owner_id") || !fabao_ob->query("series_no")) 
      return notify_fail("那个不是你的宠物耶！\n");

   
   if( !check_legal_name(newname, 60 ) )		return 1;
   
   fabao_ob->set("long", newname);
   fabao_ob->save();
   
   write("改动成功。\n");
   return 1;
}
      
int  do_change_unit(string arg)
{
   string name, newname;
   object fabao_ob, me=this_player();
  
   if( !arg || arg == "") 
      return notify_fail("请用 change_unit <法宝> <单位> 来指定法宝单位。\n");
      
   if( sscanf(arg, "%s %s", name, newname) != 2)
      return notify_fail("请用 change_unit <法宝> <单位> 来指定法宝单位。\n");
   
   if( !objectp(fabao_ob=present(name, me)) )
      return notify_fail("你身上没有这样东西啊。\n");

   if(!fabao_ob->query("owner_id") || !fabao_ob->query("series_no")) 
      return notify_fail("那个不是法宝耶！\n");

   if( fabao_ob->query("equipped") )
      return notify_fail("你必须放下法宝才能改名。\n");

   if( !check_legal_name(newname, 2 ) )		return 1;
   
   fabao_ob->set("unit", newname);
   fabao_ob->save();
   
   write("改动成功。\n");
   return 1;
}
