import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';

void main(){
  runApp(MaterialApp(home:myapp()));
}

class myapp extends StatelessWidget {
  const myapp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(

        appBar: AppBar(
          title: Text("Flutter Week 1"),
          centerTitle: true
        ),
        body: Column(
            children: [
              SizedBox(height: 50,),
              Center(
                child: CircleAvatar(
                  radius: 120,
                  backgroundImage: AssetImage('assets/images/test.png'),
                ),
              ),
              SizedBox(height: 50,),
              Text("who am I?", style: GoogleFonts.aBeeZee(
                fontSize: 50
              )),
              Container(width: 300, height: 1, color: Colors.black,),
              Text("Ans: 百變怪", style: GoogleFonts.aBeeZee(
                  fontSize: 30
              )),
              SizedBox(height: 50,),
              Container(width: 350, height: 70,decoration: BoxDecoration(color: Colors.lightBlueAccent,borderRadius: BorderRadius.circular(20)),
                child: Center(
                  child: Row(
                    children: [
                      SizedBox(width: 20, ),
                      Icon(Icons.email,size: 40,),
                      SizedBox(width: 20,),
                      Text("example@gmail.com", style: TextStyle(fontSize: 25),),
                    ],
                  ),
                ),
              ),
              SizedBox(height: 30,),
              Container(width: 350, height: 70,decoration: BoxDecoration(color: Colors.lightBlueAccent,borderRadius: BorderRadius.circular(20)),
                child: Center(
                  child: Row(
                    children: [
                      SizedBox(width: 20, ),
                      Icon(Icons.phone,size: 40,),
                      SizedBox(width: 20,),
                      Text("0912345678", style: TextStyle(fontSize: 25),),
                    ],
                  ),
                ),
              ),
            ]),
      ),
    );
  }
}
