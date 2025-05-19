import 'package:flutter/material.dart';
import 'constants.dart';
import 'color_pool.dart';
import 'dart:math';
import 'text.dart';

void main() => runApp(ScrollNotificationDemo());

class ScrollNotificationDemo extends StatefulWidget {
  const ScrollNotificationDemo({super.key});

  @override
  State<ScrollNotificationDemo> createState() => MyApp();
}

class MyApp extends State<ScrollNotificationDemo> {
  final leftController = ScrollController();
  final rightController = ScrollController();
  bool isLeftScrolling = false;
  bool isRightScrolling = false;
  int indexText = 0;
  int indexColor = 0;

  @override
  void initState() {
    super.initState();

    // 同步左側滾動到右側
    leftController.addListener(() {
      if (isRightScrolling) return; // 避免重複觸發
      isLeftScrolling = true;
      rightController.jumpTo(leftController.offset);
      isLeftScrolling = false;
    });

    // 同步右側滾動到左側
    rightController.addListener(() {
      if (isLeftScrolling) return; // 避免重複觸發
      isRightScrolling = true;
      leftController.jumpTo(rightController.offset);
      isRightScrolling = false;
    });
  }

  @override
  void dispose() {
    leftController.dispose();
    rightController.dispose();
    super.dispose();
  }

  String getTitle(List<Map<String, String>> noteData){
    indexText++;
      if(indexText>=noteData.length)
        indexText=Random().nextInt(noteData.length);
      return noteData[indexText]["title"]!;
  }

  String getDescription(List<Map<String, String>> noteData){
    return noteData[indexText]["description"]!;
  }

  int getColor(List<Color> ColorPool){
    indexColor++;
    if(indexColor>=ColorPool.length-1)
      indexColor=Random().nextInt(ColorPool.length);
    return indexColor;
  }

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
                controller: leftController,
                children: [
                  NoteCard(title: getTitle(noteData), description: getDescription(noteData),randomNumber: getColor(ColorPool)),
                  NoteCard(title: getTitle(noteData), description: getDescription(noteData),randomNumber: getColor(ColorPool)),
                  NoteCard(title: getTitle(noteData), description: getDescription(noteData),randomNumber: getColor(ColorPool)),
                  NoteCard(title: getTitle(noteData), description: getDescription(noteData),randomNumber: getColor(ColorPool)),
                  NoteCard(title: getTitle(noteData), description: getDescription(noteData),randomNumber: getColor(ColorPool)),
                  NoteCard(title: getTitle(noteData), description: getDescription(noteData),randomNumber: getColor(ColorPool)),
                  NoteCard(title: getTitle(noteData), description: getDescription(noteData),randomNumber: getColor(ColorPool)),
                  NoteCard(title: getTitle(noteData), description: getDescription(noteData),randomNumber: getColor(ColorPool)),
                  NoteCard(title: getTitle(noteData), description: getDescription(noteData),randomNumber: getColor(ColorPool)),
                ],
              ),
            ),
            Expanded(
              child: ListView(
                controller: rightController,
                children: [
                  NoteCard(title: getTitle(noteData), description: getDescription(noteData),randomNumber: getColor(ColorPool)),
                  NoteCard(title: getTitle(noteData), description: getDescription(noteData),randomNumber: getColor(ColorPool)),
                  NoteCard(title: getTitle(noteData), description: getDescription(noteData),randomNumber: getColor(ColorPool)),
                  NoteCard(title: getTitle(noteData), description: getDescription(noteData),randomNumber: getColor(ColorPool)),
                  NoteCard(title: getTitle(noteData), description: getDescription(noteData),randomNumber: getColor(ColorPool)),
                  NoteCard(title: getTitle(noteData), description: getDescription(noteData),randomNumber: getColor(ColorPool)),
                  NoteCard(title: getTitle(noteData), description: getDescription(noteData),randomNumber: getColor(ColorPool)),
                  NoteCard(title: getTitle(noteData), description: getDescription(noteData),randomNumber: getColor(ColorPool)),
                  NoteCard(title: getTitle(noteData), description: getDescription(noteData),randomNumber: getColor(ColorPool)),
                ],
              ),
            ),
          ],
        ),
      ),
    );
  }
}

class NoteCard extends StatelessWidget {
  const NoteCard({super.key, required this.title, required this.description,required this.randomNumber});

  final String title;
  final String description;
  final int randomNumber;

  @override
  Widget build(BuildContext context) {
    return Container(
      //外縮
      margin: const EdgeInsets.all(10),
      //內縮
      padding: const EdgeInsets.all(10),
      width: double.infinity,
      decoration: BoxDecoration(
        //0xFF 222831->色碼
        color: ColorPool[randomNumber],
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
