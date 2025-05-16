import 'package:flutter/material.dart';
import 'constants.dart';

void main() => runApp(MyApp());

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(title: Text('Flutter Week2'), centerTitle: true),
        body: Row(
          children: [
            Expanded(
              child: ListView(
                children: [
                  NoteCard(title: "Title 1", description: "description"),
                  NoteCard(title: "Title 2", description: "description"),
                  NoteCard(title: "Title 3", description: "description"),
                  NoteCard(title: "Title 3", description: "description"),
                  NoteCard(title: "Title 3", description: "description"),
                  NoteCard(title: "Title 3", description: "description"),
                  NoteCard(title: "Title 3", description: "description"),
                  Container(
                    margin: const EdgeInsets.all(10),
                    padding: const EdgeInsets.all(10),
                    width: double.infinity,
                    decoration: BoxDecoration(
                      color: Colors.green,
                      borderRadius: BorderRadius.circular(30),
                    ),
                    child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      children: [
                        Text("Title 2", style: kTitleTextStyle),
                        Text("decoration", style: dTitleTextStyle),
                      ],
                    ),
                  ),
                  Container(
                    margin: const EdgeInsets.all(10),
                    padding: const EdgeInsets.all(10),
                    width: double.infinity,
                    decoration: BoxDecoration(
                      color: Colors.yellow,
                      borderRadius: BorderRadius.circular(30),
                    ),
                    child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      children: [
                        Text("Title 3", style: kTitleTextStyle),
                        Text("decoration", style: dTitleTextStyle),
                      ],
                    ),
                  ),
                ],
              ),
            ),
            Expanded(child: Container(color: Colors.blue)),
          ],
        ),
      ),
    );
  }
}

class NoteCard extends StatelessWidget {
  const NoteCard({super.key, required this.title, required this.description});

  final String title;
  final String description;

  @override
  Widget build(BuildContext context) {
    return Container(
      //外縮
      margin: const EdgeInsets.all(10),
      //內縮
      padding: const EdgeInsets.all(10),
      width: double.infinity,
      decoration: BoxDecoration(
        //0xFF ECFAE5->色碼
        color: Color(0xFFECFAE5),
        borderRadius: BorderRadius.circular(30),
      ),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.start,
        children: [
          Text(title, style: kTitleTextStyle),
          Text(description, style: dTitleTextStyle),
        ],
      ),
    );
  }
}
