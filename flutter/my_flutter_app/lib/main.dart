import 'package:flutter/material.dart';

void main(){
  runApp(myapp());
}

class myapp extends StatefulWidget {
  const myapp({super.key});

  @override
  State<myapp> createState() => _myappState();
}

class _myappState extends State<myapp> {
  int counter = 0;
  void function(){
    print("on pressed");
  }
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        floatingActionButton: FloatingActionButton(
            onPressed: (){
              setState(() {
                counter++;
              });
            },
          child: Icon(Icons.add),
        ),
        appBar: AppBar(title: Text("Flutter Week 1")),
        body: Column(
          children: [
            Center(child:Text(counter.toString()))
         ]
        ),
      ),
    );
  }
}
