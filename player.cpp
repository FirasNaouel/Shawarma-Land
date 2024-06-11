#include "player.h"

using namespace std;

Player::Player() : COA() {
  name = "Zara";
  emoji = "\U0001F600";
  health = 1;
  speed = 2;
  strength = 3;
  swords[0] = new Sword();
  swords[1] = new Sword("Shawarmaster Blade", 30, 0.8, true);
  swords[2] = new Sword("Hummus Havoc", 31, 0.9, false);
  swords[3] = new Sword("Kebab Kutter", 35, 0.75, false);
  swords[4] = new Sword("4++ Smacker", 999, 0.1, false);
  potions[0] = new Potion();
  potions[1] = new Potion("Inferno Infusion Shawarma Sizzle", 40, 0.7, 2);
  potions[2] = new Potion("Cumin Courage Concoction", 50, 0.7, 0);
  swordEquipped = swords[0];

  for (int i = 0; i < 5; i++) {
    if (swords[i]->getUnlocked()) {
      list.push_back(swords[i]);
    }
  }
}

Player::~Player() {}

void Player::customize(bool c) {
  if (c) {
    cout << "Enter your character's name: ";
    getline(cin, name);

    cout << "Select an emblem for your journey (Enter corresponding number):"
         << endl;
    for (int i = 0; i < emojiSize; i++) {
      cout << i << ": " << emojis[i] << endl;
    }
    emoji = emojis[Program::question(0, 4)];
  }
}

void Player::playerInfo() {
  cout << "Name: " << Program::white() << name << Program::colourOFF() << endl;
  cout << "Emoji: " << emoji << endl;
  cout << "Health: " << Program::green() << health << " HP"
       << Program::colourOFF() << endl;
  cout << "Speed: " << Program::cyan() << speed << " SP" << Program::colourOFF()
       << endl;
  cout << "Strength: " << Program::red() << strength << " ATK"
       << Program::colourOFF() << endl;
  cout << "Sword: " << Program::white() << swordEquipped->getName()
       << Program::colourOFF() << endl;
}

Sword *Player::getSword(int index) {
  if (index >= 0 && index < 5) {
    return swords[index];
  } else {
    return nullptr;
  }
}

Potion *Player::getPotion(int index) {
  if (index >= 0 && index < 2) {
    return potions[index];
  } else {
    return nullptr;
  }
}

Sword *Player::getSwordEquipped() { return swordEquipped; }

void Player::setSwordEquipped(Sword *newItem) { swordEquipped = newItem; }

int Player::getSwordSize() { return swordSize; }

int Player::getPotionSize() { return potionSize; }

void Player::heal(int i) { health += potions[i]->usePotion(); }

void Player::addList(int s) { list.push_back(swords[s]); }

void Player::merge(Sword arr[], int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // Create temporary arrays
  Sword* L = new Sword[n1];
  Sword* R = new Sword[n2];

  // Copy data to temporary arrays L[] and R[]
  for (int i = 0; i < n1; i++)
      L[i] = arr[left + i];
  for (int j = 0; j < n2; j++)
      R[j] = arr[mid + 1 + j];

  // Merge the temporary arrays back into arr[left..right]
  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
      if (L[i].getDamage() >= R[j].getDamage()) {
          arr[k] = L[i];
          i++;
      } else {
          arr[k] = R[j];
          j++;
      }
      k++;
  }

  // Copy the remaining elements of L[], if there are any
  while (i < n1) {
      arr[k] = L[i];
      i++;
      k++;
  }

  // Copy the remaining elements of R[], if there are any
  while (j < n2) {
      arr[k] = R[j];
      j++;
      k++;
  }

  // Free the temporary arrays
  delete[] L;
  delete[] R;
}

// Function to perform merge sort on an array
void Player::mergeSort(Sword arr[], int left, int right) {
  if (left < right) {
      int mid = left + (right - left) / 2;

      // Recursively sort the first and second halves
      mergeSort(arr, left, mid);
      mergeSort(arr, mid + 1, right);

      // Merge the sorted halves
      merge(arr, left, mid, right);
  }
}

Sword Player::highDamage() {
  Sword temp[this->list.size()];

  for(int i = 0; i < list.size(); i++){
    temp[i] = *list[i];
  }
  mergeSort(temp, 0, list.size() - 1);
  return temp[0];
}
