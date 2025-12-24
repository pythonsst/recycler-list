import UIKit

@objc(HybridRecyclerlist)
class HybridRecyclerlist: NSObject {

  // Root view exposed to Fabric
  let rootView = UIView()

  // Native scroll container
  let scrollView = UIScrollView()

  // Content container (React children mount here)
  let contentView = UIView()

  override init() {
    super.init()

    rootView.translatesAutoresizingMaskIntoConstraints = false
    scrollView.translatesAutoresizingMaskIntoConstraints = false
    contentView.translatesAutoresizingMaskIntoConstraints = false

    rootView.addSubview(scrollView)
    scrollView.addSubview(contentView)

    // Pin scrollView to rootView
    NSLayoutConstraint.activate([
      scrollView.topAnchor.constraint(equalTo: rootView.topAnchor),
      scrollView.bottomAnchor.constraint(equalTo: rootView.bottomAnchor),
      scrollView.leadingAnchor.constraint(equalTo: rootView.leadingAnchor),
      scrollView.trailingAnchor.constraint(equalTo: rootView.trailingAnchor),
    ])

    // Pin contentView inside scrollView
    NSLayoutConstraint.activate([
      contentView.topAnchor.constraint(equalTo: scrollView.topAnchor),
      contentView.bottomAnchor.constraint(equalTo: scrollView.bottomAnchor),
      contentView.leadingAnchor.constraint(equalTo: scrollView.leadingAnchor),
      contentView.trailingAnchor.constraint(equalTo: scrollView.trailingAnchor),
      contentView.widthAnchor.constraint(equalTo: scrollView.widthAnchor),
    ])
  }

  // Fabric mounts children into this view
  @objc func view() -> UIView {
    return rootView
  }
}
