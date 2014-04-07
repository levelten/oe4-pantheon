// Add default styles to CKEditor.
CKEDITOR.stylesSet.add('default', [
  // Block Styles
  { name : 'Normal'		, element : 'p' },
  { name : 'Block'			, element : 'div' },
  { name : 'Blockquote'			, element : 'blockquote' },
  { name : 'Pullquote'			, element : 'blockquote', attributes : { class : 'pullquote' } },
  { name : 'Header'			, element : 'header' },
  { name : 'Footer'			, element : 'footer' },
  { name : 'Heading 2'		, element : 'h2' },
  { name : 'Heading 3'		, element : 'h3' },
  { name : 'Heading 4'		, element : 'h4' },
  { name : 'Heading 5'		, element : 'h5' },
  { name : 'Heading 6'		, element : 'h6' },
  { name : 'Preformatted Text', element : 'pre' },
  { name : 'Address'			, element : 'address' },
  // Inline Styles
  { name : 'Big'				, element : 'big' },
  { name : 'Small'			, element : 'small' },
  { name : 'Typewriter'		, element : 'tt' },
  { name : 'Computer Code'	, element : 'code' },
  { name : 'Cited Work'		, element : 'cite' },
  // Bootstrap
  { name : 'Button: Default', element: 'a', attributes : { class : 'btn btn-default' } },
  { name : 'Button: Primary', element: 'a', attributes : { class : 'btn btn-primary' } },
  { name : 'Button: Success', element: 'a', attributes : { class : 'btn btn-success' } },
  { name : 'Button: Info', element: 'a', attributes : { class : 'btn btn-info' } },
  { name : 'Button: Warning', element: 'a', attributes : { class : 'btn btn-warning' } },
  { name : 'Button: Info', element: 'a', attributes : { class : 'btn btn-info' } },
  { name : 'Button: Danger', element: 'a', attributes : { class : 'btn btn-danger' } },
  { name : 'Button: Link', element: 'a', attributes : { class : 'btn btn-link' } },

  { name : 'Primary', element : 'p', attributes : { class : 'text-primary bg-primary' } },
  { name : 'Success', element : 'p', attributes : { class : 'text-success bg-success' } },
  { name : 'Info', element : 'p', attributes : { class : 'text-info bg-info' } },
  { name : 'Warning', element : 'p', attributes : { class : 'text-warning bg-warning' } },
  { name : 'Danger', element : 'p', attributes : { class : 'text-danger bg-danger' } },

  { name : 'Alert: Success', element : 'p', attributes : { class : 'alert alert-success' } },
  { name : 'Alert: Info', element : 'p', attributes : { class : 'alert alert-info' } },
  { name : 'Alert: Warning', element : 'p', attributes : { class : 'alert alert-warning' } },
  { name : 'Alert: Danger', element : 'p', attributes : { class : 'alert alert-danger' } },

  { name : 'Well: Default', element : 'div', attributes : { class : 'well' } },
  { name : 'Well: Large', element : 'div', attributes : { class : 'well well-lg' } },
  { name : 'Well: Small', element : 'div', attributes : { class : 'well well-sm' } },

  { name : 'Label: Default', element : 'span', attributes : { class : 'label label-default' } },
  { name : 'Label: Primary', element : 'span', attributes : { class : 'label label-primary' } },
  { name : 'Label: Success', element : 'span', attributes : { class : 'label label-success' } },
  { name : 'Label: Info', element : 'span', attributes : { class : 'label label-info' } },
  { name : 'Label: Warning', element : 'span', attributes : { class : 'label label-warning' } },
  { name : 'Label: Danger', element : 'span', attributes : { class : 'label label-danger' } },

  { name : 'Badge', element : 'span', attributes : { class : 'badge' } },

  // Object Styles
  {
    name : 'Image Left',
    element : 'img',
    attributes :
    {
      'class' : 'image-left',
    }
  },
  {
    name : 'Image Right',
    element : 'img',
    attributes :
    {
      'class' : 'image-right',
    }
  },
  {
    name : 'Styled Image',
    element : 'img',
    attributes :
    {
      'class' : 'image-style',
    }
  },
  {
    name : 'Styled Image Left',
    element : 'img',
    attributes :
    {
      'class' : 'image-left-style',
    }
  },
  {
    name : 'Styled Image Right',
    element : 'img',
    attributes :
    {
      'class' : 'image-right-style',
    }
  }
]);
