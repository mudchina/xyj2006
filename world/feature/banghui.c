// create by oldsix for banghui
// because the right of write,the file u want read and write
// should at dir. /data/
#include <ansi.h>


// check the file,if exist return 1 else 0
// the parameter "file" should use entire filename
// like /data/banghui/***
int check_file(string file)
{
	if(file_size(file)==-1)
		return 0;
	return 1;
}


// get the file's data,and change to mapping data
// now have two format:
//	[name] string [value]	return string value
//      [name] int [value]      return int value
// maybe will add other format future
mapping get_file_data(string file)
{
	mapping data=([]);
	string str,name;
	mixed value;
	int i=1;
	if(! check_file(file))	return 0;
	while(str=read_file(file,i,1))	{
		if(sscanf(str,"%s string %s\n",name,value)==2)
			data[name]=value;
		if(sscanf(str,"%s int %d\n",name,value)==2)
			data[name]=value;
		i++;
	}
	return data;
}

// save the mapping data to file
int save_file_data(mapping data,string file)
{
	mixed *name,value;
	string msg="";
	int i;
	if(! data || ! file)	return 0;
	if(! check_file(file))	return 0;
	name=keys(data);
	for(i=0;i<sizeof(data);i++)	{
		value=data[name[i]];
		if(stringp(value))
			msg +=name[i]+" string "+value+"\n";
		if(intp(value))
			msg +=name[i]+" int "+value+"\n";
	}
	if(! write_file(file,msg,1))	return 0;
	return 1;
}


// when a NPC or player take part in target's banghui need :
// if "me" have taken part in some banghui,should delete me
// from it.then add "me" in "target"'s banghui
int do_jiaru(object me,object target)
{
        mapping data=([]);
        string banghui;
	string file="/data/banghui/";
	if(! (banghui=target->query("banghui"))
		|| ! check_file(file+banghui))
                return 0;
	if(! (data=get_file_data(file+banghui)))	return 0;
        data["npc"]++;
	if(me->query("zhengzhao")==4)	{
		data["dipan"]++;
	}
	if(! save_file_data(data,file+banghui))	return 0;
	if((string)(banghui=me->query("banghui"))&&
		check_file(file+banghui))	{
		data=get_file_data(file+banghui);
                data["npc"]--;
                if(data["npc"]<0)       data["npc"]=0;
		if(me->query("zhengzhao")==4)	{
			data["dipan"]--;
			if(data["dipan"]<0)	data["dipan"]=0;
		}
		save_file_data(data,file+banghui);
        }
	data=me->get_npc_data();
        data["banghui"]=target->query("banghui");
	me->set_npc_data(data,1);
	me->save_npc_data(data);
	if(me->query_temp("target"))	me->delete_temp("target");
	if(me->query_temp("money"))	me->delete_temp("money");
	if(me->query_temp("stuffname")) me->delete_temp("stuffname");
	if(me->query_temp("stuffid"))   me->delete_temp("stuffid");
	message_vision(HIY"$N加入$n的帮会「"+target->query("banghui")
	+"」。\n"NOR,me,target);
        return 1;
}

// if me is bangzhu,will return 1,because only player can be bangzhu
// so this function should apply to player
int is_bangzhu(object me)
{
	string banghui;
	string file="/data/banghui/";
	mapping data;
	if(! (banghui=me->query("banghui"))||
		! check_file(file+banghui))
			return 0;
	if(! (data=get_file_data(file+banghui)))	return 0;
	if(data["bangzhu"]!=me->query("id"))		return 0;
	return 1;
}
