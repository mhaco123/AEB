
import muvium.compatibility.arduino.*; 

class ToneMelody extends Arduino{ 
 
  int[] melody    = new int[]{ 
     Pitches.NOTE_C4, Pitches.NOTE_G3, Pitches.NOTE_G3, Pitches.NOTE_A3, Pitches.NOTE_G3, 0, Pitches.NOTE_B3, Pitches.NOTE_C4 };

  int[] noteDurations  = new int[] {  
    4, 8, 8, 4,4,4,4,4 }; 
  
  public void setup() {  
   
  }  
 
  public void loop() { 
    // no need to repeat the melody.  
    // iterate over the notes of the melody: 
    for (int thisNote = 0; thisNote < 8; thisNote++) {  
      // to calculate the note duration, take one second   
      // divided by the note type.  
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.  
      int noteDuration = 1000 / noteDurations[thisNote];  
      tone(8, melody[thisNote], noteDuration);  

      // to distinguish the notes, set a minimum time between them.  
      // the note's duration + 30% seems to work well:  
      int pauseBetweenNotes = (int) ( noteDuration * 1.30 );  
      delay(pauseBetweenNotes);  
    }  
    delay(2000); 
  }
 
}
