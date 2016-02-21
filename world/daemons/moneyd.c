// 欢乐英雄！--kicker(hisy@163.net)

#include <ansi.h>

int move_money(int amount);
int write_money_log(object room,int amount);
int get_number();
int get_write_number();
void write_log(object room_o,string number);
int del_log(string x);


string money_str(int amount)
{
        // returns a chinese string of `amount` of money
        string output;

        if (amount / 10000) {
                output = chinese_number(amount / 10000) + "两"HIY"黄金"NOR;
                amount %= 10000;
        }
        else
                output = "";
        if (amount / 100) {
                output = output + chinese_number(amount / 100) + "两"HIW"白银"NOR;
                amount %= 100;
        }
        if (amount)
                return output + chinese_number(amount) + "文"YEL"铜板"NOR;
        return output;
}


int move_money(int amount)
{
	string *path = ({
		"/d/city/",
	});
	string mvdir,*dir,room_s;
	int f;
	object room_o;
	
	mvdir=path[random(sizeof(path))];
	dir=get_dir(mvdir);
	
	room_s=dir[random(sizeof(dir))];
	room_s=mvdir+room_s;
	room_o=find_object(room_s);
	if(!room_o) room_o=load_object(room_s);
	if(!room_o) return 0;
	
        amount>=1000 ?f=amount:f=70+random(200);
	write_money_log(room_o,f);
	
	return 1;
}

int write_money_log(object room,int amount)
{
	int i,x;
        if(random(100)<=700) {
                message("chat",HIR"\n财神爷突然降临人间，把地上的黄金全收走了……\n\n"NOR,users());
		rm("/log/dlog/money");
		return 0;
	}
	if((i=get_number())>=20) return 0;
	if(!(x=get_write_number())) return 0;
	room->set( "dig_money/value",amount);
	room->set( "dig_money/number",x);
	write_log(room,""+x+"");
}

int get_number()
{
	string msg,*line;
	int i,x=0;
	if(!(msg=read_file("/log/dlog/money"))) return 0;
	line=explode(msg,"\n");
	for(i=0;i<sizeof(line);i++) {
		if(line[i]=="") continue;
		if(strlen(line[i])>2 || to_int(line[i])>20 || to_int(line[i])<1 ) continue;
		x++;
	}
	return x;
}

int get_write_number()
{
	int i,x,k,*ar=({});
	string msg,*line;
	if(!(msg=read_file("/log/dlog/money"))) return 1;
	line=explode(msg,"\n");
	for(x=0;x<sizeof(line);x++) {
		if(line[x]=="") continue;
		if(strlen(line[i])>2 || (k=to_int(line[x]))>20 || k<1 ) continue;
		ar+=({k});
	}
	for(i=1;i<=20;i++)
		if(member_array(i,ar)==-1) return i;
	return 0;
}

void write_log(object room_o,string number)
{
	string r_long;
	int j,k;
	r_long=room_o->query("long");
	j=strlen(r_long);
	//往房间描述里面加一些“□”，使找的工作变得难些。
	for(int x=0;x<j;x+=2) {
		if(r_long[x]<=160 || r_long[x]>=255 ) {
			x--;
			continue;
		}
                if(random(10)<4) {
			k=x+1;
			r_long=replace_string(r_long,r_long[x..k],"□");
		}
	}
	write_file("/log/dlog/money",number+"\n");
	write_file("/log/dlog/money",r_long);
	message("chat",CYN"\n天降财神，有宝落民间了！似乎在：\n"NOR,users());
	message("chat",r_long,users());
}

int del_log(string x)
{
	string news="",olds,*line;
	int i,Bool=0,k;

	if( !( olds=read_file("/log/dlog/money") ) ) return 0;
	line=explode(olds,"\n");
	news="";
	for(i=0;i<sizeof(line);i++) {
		if(x==line[i]) Bool=1;
		if( Bool==1
		 && strlen(line[i])<=2
		 && line[i]!=x
		 && ( k=to_int(line[i]) )<=20
		 && k>=1 ) Bool=0;
		if(Bool==1) continue;
		news+=(line[i]+"\n");
	}
	rm("/log/dlog/money");
	write_file("/log/dlog/money",news);
	return 1;
}

string show_msg()
{
	string olds,news="",*line;
	int i,k,x,Bool=0,f=0,y;
	if( !(x=get_number())) return 0;
	k=random(x)+1;
	
	olds=read_file("/log/dlog/money");
	line=explode(olds,"\n");

	for(i=0;i<sizeof(line);i++) {
		if( strlen(line[i])<=2
		&& (y=to_int(line[i]))<=20
		&& y>=1 ) f++;
		if(f==k && Bool==0) Bool=1;
		if(f>k && Bool==1) Bool=0;
		if(Bool==0) continue;
		if( strlen(line[i])<=2
		&& y<=20
		&& y>=1 ) continue;
		news+=(line[i]+"\n");
	}
	return news;
}
	
	
