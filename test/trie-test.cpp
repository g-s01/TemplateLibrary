#include <gtest/gtest.h>
#include "../src/Trie/trie.cpp"

TEST(TrieTest, InsertWordTest) {
    Trie trie;
    trie.InsertWord("gautam");
    ASSERT_TRUE(trie.SearchWord("gautam")) << "should insert word correctly" << '\n';
}

TEST(TrieTest, SearchWordTest) {
    Trie trie;
    trie.InsertWord("gautam");
    ASSERT_TRUE(trie.SearchWord("gautam")) << "should return true if the word is there in the trie" << '\n';
    ASSERT_FALSE(trie.SearchWord("sharma")) << "should return true if the word is there in the trie" << '\n';
}

TEST(TrieTest, DeleteWordTest) {
    Trie trie;
    trie.InsertWord("gautam");
    ASSERT_TRUE(trie.SearchWord("gautam"));
    trie.DeleteWord("gautam");
    ASSERT_FALSE(trie.SearchWord("gautam")) << "should delete word correctly"<< '\n';
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}