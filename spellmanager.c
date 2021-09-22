

int main()
{
    SpellChecker* spell = createSpellChecker();
    Dictionary* dictList = createDictionaryList();

    menu(spell, dictList);

    freeCatalogue(spell);
    freeBorrowerList(dictList);

    return 0;
}