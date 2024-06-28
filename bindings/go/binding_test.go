package tree_sitter_TNSL_test

import (
	"testing"

	tree_sitter "github.com/smacker/go-tree-sitter"
	"github.com/tree-sitter/tree-sitter-TNSL"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_TNSL.Language())
	if language == nil {
		t.Errorf("Error loading Tnsl grammar")
	}
}
